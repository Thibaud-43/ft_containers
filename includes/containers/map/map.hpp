#ifndef MAP_H
 #define MAP_H

#include <ReverseIterator.hpp>
#include <IteratorTraits.hpp>
#include <MapIterator.hpp>
#include <pair.hpp>
#include <string>
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

template <class Key, class T>
struct BNode
{
	pair<Key, T> 	pair;
	BNode 			*left;
	BNode 			*right;
	BNode 			*parent;
	bool 			end;
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
	typedef MapIterator<value_type>				iterator;
	typedef MapIterator<value_type> 			const_iterator;
	typedef ReverseIterator<iterator> 			reverse_iterator;
	typedef ReverseIterator<const_iterator> 	const_reverse_iterator;
	typedef std::ptrdiff_t 						difference_type;
	typedef	size_t								size_type;
	typedef	BNode<key_type, mapped_type>*		node_type;



/***********************************************************************************************************************************
*															CONSTRUCTORS / DESTRUCTORS														
***********************************************************************************************************************************/

	explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
	:m_root(nullptr), m_size(0), m_alloc(alloc), m_comp(comp)
	{

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

	}

/***********************************************************************************************************************************
*															ITERATORS																
***********************************************************************************************************************************/

	iterator begin()
	{

	}
	const_iterator begin() const
	{

	}
	iterator end()
	{

	}
	const_iterator end() const
	{

	}
	reverse_iterator rbegin()
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

	}

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


	/*pair<iterator,bool> insert (const value_type& val)
	{

	}



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
		size_type		m_size;
		allocator_type	m_alloc;
		node_type		m_root;
		key_compare		m_comp;

/***********************************************************************************************************************************
*															EXTRA : BINARY TREE FUNCTON																
***********************************************************************************************************************************/
		init();
		free();
		insert();
		delete();

};


}
#endif