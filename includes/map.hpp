#ifndef MAP_H
 #define MAP_H

#include "ReverseIterators.hpp"
#include <IteratorTraits.hpp>
#include <MapIterator.hpp>
#include <is_integral.hpp>
#include <string>
#include <pair.hpp>
#include <limits>
#include <iostream>
#include <memory>

namespace ft
{


template<class InputIt1, class InputIt2>
bool equal(InputIt1 first1, InputIt1 last1, 
           InputIt2 first2)
{
    for (; first1 != last1; ++first1, ++first2) 
	{
        if (!(*first1 == *first2)) 
		{
            return false;
        }
    }
    return true;
}

template<class InputIt1, class InputIt2>
bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
                             InputIt2 first2, InputIt2 last2)
{
    for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) 
	{
        if (*first1 < *first2) return true;
        if (*first2 < *first1) return false;
    }
    return (first1 == last1) && (first2 != last2);
}

template <class Arg1, class Arg2, class Result>
struct binary_function 
{
    typedef Arg1 first_argument_type;
    typedef Arg2 second_argument_type;
    typedef Result result_type;
};

template <class T> 
struct less : binary_function <T,T,bool> 
{
	bool operator() (const T& x, const T& y) const 
	{
		return x<y;
	}
};

template <class  Key, class T>
struct BNode
{
	pair<Key, T> 		pair;
	BNode 				*left;
	BNode 				*right;
	BNode 				*parent;
	bool 				end;
	bool				root;
};

template < class Key,                                     		// map::key_type
           class T,                                       		// map::mapped_type
           class Compare = ft::less<Key>,                     	// map::key_compare
           class Alloc = std::allocator<pair<const Key,T> >    // map::allocator_type
           >
class map
{

public:

/***********************************************************************************************************************************
*															TYPEDEF																
***********************************************************************************************************************************/
	
	typedef	Key									key_type;
	typedef T									mapped_type;
	typedef pair<const Key, T> 					value_type;
	typedef	Compare								key_compare;
	class 	value_compare
	{   
		class map;
		protected:
			Compare comp;
			value_compare (Compare c) : comp(c) 
			{

			}
		public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;
			bool operator() (const value_type& x, const value_type& y) const
			{
				return comp(x.first, y.first);
			}
	};
	typedef Alloc											allocator_type;
	typedef std::allocator<BNode<key_type, mapped_type> >	node_allocator_type;
	typedef	value_type	&									reference;
	typedef	value_type const &								const_reference;
	typedef	value_type	*									pointer;
	typedef	value_type const *								const_pointer;
	typedef MapIterator<key_type, mapped_type>				iterator;
	typedef MapIterator<key_type, mapped_type> 				const_iterator;
	typedef ReverseIterator<iterator> 						reverse_iterator;
	typedef ReverseIterator<const_iterator> 				const_reverse_iterator;
	typedef std::ptrdiff_t 									difference_type;
	typedef	size_t											size_type;
	typedef	BNode<key_type, mapped_type>*					node_type;



/***********************************************************************************************************************************
*															CONSTRUCTORS / DESTRUCTORS														
***********************************************************************************************************************************/

	explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
	:m_root(NULL), m_size(0), m_alloc(alloc), m_node_alloc(node_allocator_type()), m_comp(comp)
	{
		init();
	}

	template <class InputIterator>
	map (InputIterator first, 
		typename ft::enable_if<ft::is_iterator<InputIterator>::value && (!ft::is_integral<InputIterator>::value), InputIterator>::type last,
		const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type())
		:m_root(NULL), m_size(0), m_alloc(alloc), m_node_alloc(node_allocator_type()), m_comp(comp)
	{
		init();
		insert(first, last);
	}

	map (const map& x):
	m_root(NULL), m_size(0), m_alloc(x.m_alloc), m_node_alloc(node_allocator_type()), m_comp(x.m_comp)
	{
		init();
		insert(x.begin(), x.end());
	}
	map &operator=(const map<Key, T> &rhs)
	{
		clear();
		insert(rhs.begin(), rhs.end());
		return (*this);
	};
	~map()
	{
		free_tree(m_root);
	}

/***********************************************************************************************************************************
*															ITERATORS																
***********************************************************************************************************************************/

	iterator begin()
	{
		node_type n = m_root;
		if (!n->left && !n->right)
			return (iterator(n));
		if (!n->left && n->right)
			n = n->right;
		while (n->left)
			n = n->left;
		return (iterator(n));
	}
	const_iterator begin() const
	{
		node_type n = m_root;
		if (!n->left && !n->right)
			return (const_iterator(n));
		if (!n->left && n->right)
			n = n->right;
		while (n->left)
			n = n->left;
		return (const_iterator(n));
	}
	iterator end()
	{
		node_type n = m_root;
		if (!n->left && !n->right)
			return (iterator(n));
		while (!n->end)
			n = n->right;
		return (iterator(n));
	}
	const_iterator end() const
	{
		node_type n = m_root;
		if (!n->left && !n->right)
			return (const_iterator(n));
		while (!n->end)
			n = n->right;
		return (const_iterator(n));
	}
	reverse_iterator rbegin()
	{
		iterator	n = end();
		return (reverse_iterator(n));
	}
	const_reverse_iterator rbegin() const
	{
		iterator	n = end();
		return (const_reverse_iterator(n));
	}
	reverse_iterator rend()
	{
		return(--reverse_iterator(m_root));
	}
	const_reverse_iterator rend() const
	{
		return(--const_reverse_iterator(m_root));
	}

/***********************************************************************************************************************************
*															CAPACITY																
***********************************************************************************************************************************/
	bool empty() const
	{
		if (m_size == 0)
			return true;
		return false;
		
	}
	size_type size() const
	{
		return m_size;
	}
	size_type max_size(void) const
	{
		return (m_alloc.max_size());
	};

/***********************************************************************************************************************************
*															ELEMENT ACCESS																
***********************************************************************************************************************************/
	
	mapped_type& operator[] (const key_type& k)
	{
		node_type	tmp = find_key(k, m_root);
		if (tmp)
			return(tmp->pair.second);
		else
		{
			return (insert(value_type(k, mapped_type())).first->second);
		}
	}
	


/***********************************************************************************************************************************
*															MODIFIERS																
***********************************************************************************************************************************/

	pair<iterator,bool> insert (const value_type& val)
	{
		node_type	tmp = find_key(val.first, m_root);
		if (tmp)
			return(pair<iterator, bool>(iterator(tmp), false));
		else
		{
			m_size++;
			return (pair<iterator, bool>(iterator(add_node(val, m_root)), true));
		}
	}



	iterator insert (iterator position, const value_type& val)
	{
		node_type	tmp = find_key(val.first, m_root);
		if (tmp)
			return(tmp);
		else
		{
			m_size++;
			return (iterator(add_node(val, position.node())));
		}
	}

	template <class InputIterator>
	void insert (InputIterator first, 
	typename ft::enable_if<ft::is_iterator<InputIterator>::value && (!ft::is_integral<InputIterator>::value), InputIterator>::type last)
	{
		while (first != last)
		{
			insert(*first);
			first++;
		}
		
	}



	void erase (iterator position)
	{

		remove_node(position.node());
		m_size--;
	}



	size_type erase (const key_type& k)
	{
		int count = 0;
		node_type	elem;
		while ((elem = find_key(k, m_root)))
		{
			erase(iterator(elem));
			++count;
		};
		return (count);
	}



	void erase (iterator first, iterator last)
	{
		while (first != last)
			erase(first++);
	}
	void swap (map& x)
	{
		node_type		tmp = x.m_root;
	
		x.m_root = this->m_root;

		this->m_root = tmp;

	}
	void clear()
	{	
		erase(begin(), end());
	}

/***********************************************************************************************************************************
*															OBSERVERS																
***********************************************************************************************************************************/

	key_compare key_comp() const
	{
		return m_comp;
	}
	value_compare value_comp() const
	{
		return this->value_compare;
	}

/***********************************************************************************************************************************
*															OPERATIONS														
***********************************************************************************************************************************/
	iterator find (const key_type& k)
	{
		node_type	tmp = find_key(k, m_root);
		return(iterator(tmp));
	}
	const_iterator find (const key_type& k) const
	{
		node_type	tmp = find_key(k, m_root);
		return(const_iterator(tmp));
	}
	size_type count (const key_type& k) const
	{
		node_type	tmp = find_key(k, m_root);
		if (!tmp)
			return 0;
		return 1;
	}
	iterator lower_bound (const key_type& k)
	{
		iterator	tmp = begin();
		while (tmp != end())
		{
			if(m_comp(tmp->first, k) <= 0)
				return((tmp));
			tmp++;
		}
		return ((tmp));
		
	}
	const_iterator lower_bound (const key_type& k) const
	{
		const_iterator	tmp = begin();
		while (tmp != end())
		{
			if(m_comp(tmp->first, k) <= 0)
				return((tmp));
			tmp++;
		}
		return ((tmp));
	}
	iterator upper_bound (const key_type& k)
	{
		iterator	tmp = begin();
		while (tmp != end())
		{
			if(m_comp(tmp->first, k) <= 0 && tmp->first != k)
				return((tmp));
			tmp++;
		}
		return ((tmp));
	}
	const_iterator upper_bound (const key_type& k) const
	{
		const_iterator	tmp = begin();
		while (tmp != end())
		{
			if(m_comp(tmp->first, k) <= 0 && tmp->first != k)
				return((tmp));
			tmp++;
		}
		return ((tmp));
	}
	pair<const_iterator,const_iterator> equal_range (const key_type& k) const
	{
		return (pair<const_iterator, const_iterator>(this->lower_bound(k), this->upper_bound(k)));
	}
	pair<iterator,iterator>             equal_range (const key_type& k)
	{
		return (pair<iterator, iterator>(this->lower_bound(k), this->upper_bound(k)));
	}
/***********************************************************************************************************************************
*															ALLOCATOR																
***********************************************************************************************************************************/
	allocator_type get_allocator() const
	{
		return m_alloc;
	}


/***********************************************************************************************************************************
*															PRIVATE ATTRIBUTES																
***********************************************************************************************************************************/
	
	private :
		node_type				m_root;
		node_type				m_end;
		size_type				m_size;
		allocator_type			m_alloc;
		node_allocator_type		m_node_alloc;
		key_compare				m_comp;

/***********************************************************************************************************************************
*															EXTRA : BINARY TREE FUNCTON																
***********************************************************************************************************************************/	
		void print_tree(node_type n)
		{
			if (!n)
				return;
			print_tree(n->left);
			std::cout << n->pair.first << "=" << n->pair.second << std::endl;
			print_tree(n->right);
		};

		void	init(void)
		{
			m_root = create_node(value_type(key_type(), mapped_type()), NULL, false, true);
			m_root->right = create_node(value_type(key_type(), mapped_type()), m_root, true);

		}

		node_type	create_node(value_type	pair, node_type parent, bool end = false, bool root = false)
		{
			node_type elem = m_node_alloc.allocate(1);
			//node_type	elem = new	BNode<key_type, mapped_type>();

			elem->pair = pair;
			elem->parent = parent;
			elem->right = NULL;
			elem->left = NULL;
			elem->root = root;
			elem->end = end;
			return elem;
		}
		node_type		find_key(key_type key, node_type current) const
		{
			node_type	ret1 = NULL;
			node_type	ret2 = NULL;
			if (current->left)
				ret1 = find_key(key, current->left);
			if (current->right)
				ret2 = find_key(key, current->right);
			if (current->pair.first == key)
			{
				return current;
			}
			else
			{
				if (ret1)
					return ret1;
				else if (ret2)
					return ret2;
				else
					return NULL;
			}
			
		}
		node_type		add_node(pair<key_type, mapped_type> pair, node_type current)
		{
			if (pair.first > current->pair.first)
			{
				if(current->right && !current->right->end)
				{
					return add_node(pair, current->right);
				}
				else
				{
					if (!current->right)
					{
						current->right = create_node(pair, current);
						return(current->right);
					}
					else
					{
						node_type	tmp = current->right;
						current->right = create_node(pair, current);
						current->right->right = tmp;
						current->right->right->parent = current->right;
						return(current->right);
					}
				}
			}
			else
			{
				if (current->left)
				{
					return add_node(pair, current->left);
				}
				else
				{
					current->left = create_node(pair, current, true);
					return(current->left);

				}
				
			}
			
		}
		void	remove_node(node_type current)
		{

			node_type parent = current->parent;
			if (!current->left && !current->right)
			{
				if (parent->right == current)
					parent->right = 0;
				else
					parent->left = 0;
				m_node_alloc.deallocate(current, 1);
				//delete current;
				return ;
			}
			if (current->right && !current->left)
			{
				if (parent->right == current)
					parent->right = current->right;
				else
					parent->left = current->right;
				current->right->parent = parent;
				m_node_alloc.deallocate(current, 1);
				//delete current;
				return ;
			}
			if (current->left && !current->right)
			{
				if (parent->right == current)
					parent->right = current->left;
				else
					parent->left = current->left;
				current->left->parent = parent;
				m_node_alloc.deallocate(current, 1);
				//delete current;
				return ;
			}
			node_type next = (++iterator(current)).node();
			/*if (!next)
				next = (--iterator(current)).node();*/
			pair<key_type, mapped_type>	tmp;
			tmp = current->pair;
			current->pair = next->pair;
			next->pair = tmp;
			remove_node(next);
		}
		void	free_tree(node_type current)
		{
			std::allocator<BNode<key_type, mapped_type> >	alloc;
			if (current->left)
				free_tree(current->left);
			if (current->right)
				free_tree(current->right);
			m_node_alloc.deallocate(current, 1);
			//delete current;
		}
};
	template <class Key, class T, class Compare, class Alloc>
	void swap(ft::map<Key, T, Compare, Alloc> &x, ft::map<Key, T, Compare, Alloc> &y)
	{
		x.swap(y);
	};
	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		typename ft::map<Key, T, Compare, Alloc>::const_iterator it = rhs.begin();
		typename ft::map<Key, T, Compare, Alloc>::const_iterator it2 = lhs.begin();
		while (it != rhs.end())
		{
			if (*it != *it2)
				return (false);
			++it2;
			++it;
		}
		return (true);
	};
	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(lhs == rhs));
	};
	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return(lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	};
	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(lhs > rhs) && !(lhs == rhs));
	};
	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(lhs < rhs));
	};
	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(lhs > rhs));
	};

}
#endif