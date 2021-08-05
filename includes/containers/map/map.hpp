#ifndef MAP_H
 #define MAP_H

#include <ReverseIterator.hpp>
#include <IteratorTraits.hpp>
#include <MapIterator.hpp>
#include <string>
#include <pair.hpp>
#include <limits>
#include <iostream>
#include <memory>

namespace ft
{

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
	bool 				end_branch;
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
		friend class map;
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
	typedef Alloc								allocator_type;
	typedef	value_type	&						reference;
	typedef	value_type const &					const_reference;
	typedef	value_type	*						pointer;
	typedef	value_type const *					const_pointer;
	typedef MapIterator<key_type, mapped_type>	iterator;
	typedef MapIterator<key_type, mapped_type> 	const_iterator;
	typedef ReverseIterator<iterator> 			reverse_iterator;
	typedef ReverseIterator<const_iterator> 	const_reverse_iterator;
	typedef std::ptrdiff_t 						difference_type;
	typedef	size_t								size_type;
	typedef	BNode<key_type, mapped_type>*		node_type;



/***********************************************************************************************************************************
*															CONSTRUCTORS / DESTRUCTORS														
***********************************************************************************************************************************/

	explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
	:m_root(NULL), m_size(0), m_alloc(alloc), m_comp(comp)
	{
		init();


	}

	/*template <class InputIterator>
	map (InputIterator first, InputIterator last,
		const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type())
	{
		
	}

	map (const map& x)
	{

	}*/

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
	/*reverse_iterator rbegin()
	{

	}
	const_reverse_iterator rbegin() const
	{

	}
	reverse_iterator rend()
	{

	}
	const_reverse_iterator rend() const
	{

	}*/

/***********************************************************************************************************************************
*															CAPACITY																
***********************************************************************************************************************************/
	bool empty() const
	{

	}
	size_type size() const
	{

	}
	

/***********************************************************************************************************************************
*															ELEMENT ACCESS																
***********************************************************************************************************************************/
	
	/*mapped_type& operator[] (const key_type& k)
	{

	}*/
	


/***********************************************************************************************************************************
*															MODIFIERS																
***********************************************************************************************************************************/

	pair<iterator,bool> insert (const value_type& val)
	{
		node_type	tmp = find(val.first, m_root);
		if (tmp)
			return(pair<iterator, bool>(iterator(tmp), false));
		else
		{
			m_size++;
			return (pair<iterator, bool>(iterator(add_node(val, m_root)), true));
		}
	}


/*
	iterator insert (iterator position, const value_type& val)
	{

	}



	template <class InputIterator>
	void insert (InputIterator first, InputIterator last)
	{

	}



	void erase (iterator position)
	{

	}



	size_type erase (const key_type& k)
	{

	}



	void erase (iterator first, iterator last)
	{

	}
	void swap (map& x)
	{

	}*/
	void clear()
	{

	}

/***********************************************************************************************************************************
*															OBSERVERS																
***********************************************************************************************************************************/

	key_compare key_comp() const
	{

	}
	value_compare value_comp() const
	{

	}

/***********************************************************************************************************************************
*															OPERATIONS														
***********************************************************************************************************************************/
	/*iterator find (const key_type& k)
	{

	}
	const_iterator find (const key_type& k) const
	{

	}
	size_type count (const key_type& k) const
	{

	}
	iterator lower_bound (const key_type& k)
	{

	}
	const_iterator lower_bound (const key_type& k) const
	{

	}
	iterator upper_bound (const key_type& k)
	{

	}
	const_iterator upper_bound (const key_type& k) const
	{

	}
	pair<const_iterator,const_iterator> equal_range (const key_type& k) const
	{

	}
	pair<iterator,iterator>             equal_range (const key_type& k)
	{

	}*/
/***********************************************************************************************************************************
*															ALLOCATOR																
***********************************************************************************************************************************/
allocator_type get_allocator() const
{

}


/***********************************************************************************************************************************
*															PRIVATE ATTRIBUTES																
***********************************************************************************************************************************/
	
	private :
		node_type		m_root;
		size_type		m_size;
		allocator_type	m_alloc;
		key_compare		m_comp;

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
			m_root = create_node(value_type(key_type(), mapped_type()), NULL, true, true, false);
			m_root->right = create_node(value_type(key_type(), mapped_type()), NULL, true, false, true);
		}

		node_type	create_node(value_type	pair, node_type parent, bool end_branch, bool root = false, bool end = false, node_type node_end = NULL)
		{

			node_type	elem = new	BNode<key_type, mapped_type>();

			elem->pair = pair;
			elem->parent = parent;
			elem->right = node_end;
			elem->left = NULL;
			elem->end_branch = end_branch;
			elem->root = root;
			elem->end = end;
			return elem;
		}
		node_type		find(key_type key, node_type current)
		{
			node_type	ret1 = NULL;
			node_type	ret2 = NULL;
			if (current->left)
				ret1 = find(key, current->left);
			if (current->right)
				ret2 = find(key, current->right);
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
			if (current->end_branch)
			{
				if (pair > current->pair)
				{
					if (current->right && current->right->end)
					{
						current->end_branch = false;
						current->right = create_node(pair, current, true, false, false, current->right);
						current->right->right->parent = current->right;
						return(current->right);
					}
					else
					{
						current->end_branch = false;
						current->right = create_node(pair, current, true);
						return(current->right);
					}
				}
				else
				{
					current->end_branch = false;
					current->left = create_node(pair, current, true);
					return(current->left);
				}
			}
			else if (pair > current->pair)
				 return(add_node(pair, current->right));
			else
				return(add_node(pair, current->left));
		}

		void	free_tree(node_type current)
		{
			if (current->left)
				free_tree(current->left);
			if (current->right)
				free_tree(current->right);
			delete current;
		}

};


}
#endif