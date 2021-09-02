#ifndef Vector_HPP
 #define Vector_HPP

#include <VectorIterators.hpp>
#include "RandomAccessIterators.hpp"
#include <ReverseIterators.hpp>
#include <IteratorTraits.hpp>
#include <is_integral.hpp>
#include <string>
#include <string.h>
#include <limits>
#include <iostream>
#include <memory>


namespace ft
{


template<typename T, class Alloc = std::allocator<T> >
class vector
{

public:

/***********************************************************************************************************************************
*															TYPEDEF																
***********************************************************************************************************************************/
	typedef	T									value_type;
	typedef Alloc								allocator_type;
	typedef	value_type	&						reference;
	typedef	value_type const &					const_reference;
	typedef	value_type	*						pointer;
	typedef	value_type const *					const_pointer;
	typedef VectorIterator<value_type>			iterator;
	typedef ConstVectorIterator<value_type>		const_iterator;
	typedef ReverseIterator<iterator> 			reverse_iterator;
	typedef ReverseIterator<const_iterator> 	const_reverse_iterator;
	typedef std::ptrdiff_t 						difference_type;
	typedef	size_t								size_type;



/***********************************************************************************************************************************
*															CONSTRUCTORS / DESTRUCTORS														
***********************************************************************************************************************************/

	explicit vector (const allocator_type& alloc = allocator_type()): m_data(NULL), m_size(0), m_capacity(0), m_alloc(alloc)   
	{

	}

	explicit vector (int n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): 
	m_data(NULL), m_size(0), m_capacity(0), m_alloc(alloc)
	{
		this->assign(n, val);
	}

	template <class InputIterator>
    vector (InputIterator first, 
	typename ft::enable_if<ft::is_iterator<InputIterator>::value && (!ft::is_integral<InputIterator>::value), InputIterator>::type last, 
	const allocator_type& alloc = allocator_type()):
	m_data(NULL), m_size(0), m_capacity(0), m_alloc(alloc)
	{
		this->assign(first, last);
	}

	vector (const vector & x): m_data(NULL), m_size(0), m_capacity(0), m_alloc(x.m_alloc)
	{
		reserve(x.m_capacity);
		memcpy(static_cast<void*>(m_data), static_cast<void*>(x.m_data), x.m_size * sizeof(value_type));
		m_size = x.size();
	}

	~vector()
	{
		this->clear();
		m_alloc.deallocate(m_data, m_capacity);
	};

	vector &operator=(const vector &other)
	{

		m_size = 0;
		m_alloc.deallocate(m_data, m_capacity);
		m_alloc = other.m_alloc;
		if (other.m_size > m_capacity)
			m_capacity = other.m_size;
		m_data = m_alloc.allocate(m_capacity);
		for (const_iterator it = other.begin(); it != other.end(); it++)
		{
			this->push_back(*it);
		}
		return *this;
	}

/***********************************************************************************************************************************
*															ITERATORS																
***********************************************************************************************************************************/
	const_iterator	begin(void) const
	{
		return  const_iterator(m_data);
	}

	iterator	begin(void)
	{
		return iterator(m_data);
	}

	iterator	end()
	{
		return iterator(m_data + m_size);
	}

	const_iterator	end() const
	{
		return const_iterator(m_data + m_size);
	}

	reverse_iterator	rbegin()
	{
		return reverse_iterator(m_data + m_size);
	}
	const_reverse_iterator	rbegin() const
	{
		return const_reverse_iterator(m_data + m_size);
	}
	reverse_iterator	rend()
	{
		return reverse_iterator(m_data);
	}
	const_reverse_iterator	rend() const
	{
		return const_reverse_iterator(m_data);
	}

/***********************************************************************************************************************************
*															CAPACITY																
***********************************************************************************************************************************/
	
	size_type		size(void) const
	{
		return m_size;
	}

	size_type max_size() const
	{
		return (m_alloc.max_size());
	}

	void resize (size_type n, value_type val = value_type())
	{
		if (n > m_size * 2)
		{
			reserve(n);
		}
		else if (n > m_capacity)
		{
			reserve(m_size*2);
		}
		
		while (n < m_size)
			pop_back();
		while(n > m_size)
			push_back(val);
		
	}
	size_type		capacity(void) const
	{
		return m_capacity;
	}

	bool empty() const
	{
		if (m_size == 0)
		{
			return true;
		}
		return false;
		
	}
	void reserve (size_type n)
	{
		T	*tmp;
		if (n > m_capacity)
		{
			tmp = m_alloc.allocate(n);
			for (size_t i = 0; i < m_size; i++)
			{
				m_alloc.construct(&tmp[i], m_data[i]);
				m_alloc.destroy(&m_data[i]);
			}
			m_alloc.deallocate(m_data, m_capacity);
			m_data = tmp;
			m_capacity = n;
		}

	}

/***********************************************************************************************************************************
*															ELEMENT ACCESS																
***********************************************************************************************************************************/
	
	reference operator[] (size_type n)
	{
		return *(this->begin() + n);
	}
	const_reference operator[] (size_type n) const
	{
		return *(this->begin() + n);
	}
	reference at (size_type n)
	{
		if (n >= this->m_size)
			throw (std::out_of_range("out of range"));
		return (this->m_data[n]);
	}
	const_reference at (size_type n) const
	{
		if (n >= this->m_size)
			throw (std::out_of_range("out of range"));
		return (this->m_data[n]);
	}
	reference front()
	{
		return m_data[0];
	}
	const_reference front() const
	{
		return m_data[0];
	}
	reference back()
	{
		return *(this->end()-1);
	}
	const_reference back() const
	{
		return *(this->end()-1);
	}


/***********************************************************************************************************************************
*															MODIFIERS																
***********************************************************************************************************************************/
	
	template <class InputIterator>
	void assign (InputIterator first, typename ft::enable_if<ft::is_iterator<InputIterator>::value && (!ft::is_integral<InputIterator>::value), InputIterator>::type last)
	{
		InputIterator tmp = first;
		m_alloc.deallocate(m_data, m_capacity);
		size_type	k = 0;
		for ( ; tmp != last; tmp++)
			k++;
		if (k > m_capacity)
			m_capacity = k;
		m_data = m_alloc.allocate(k);
		m_size = 0;
		for (InputIterator it = first; it != last; it++)
		{
			this->push_back(*it);
		}

	}

	void assign (int n, const value_type& val)
	{
		m_alloc.deallocate(m_data, m_capacity);
		if (static_cast<size_type>(n) > m_capacity)	
			m_capacity = static_cast<size_type>(n);
		m_size = 0;
		m_data = m_alloc.allocate(m_capacity);
		for (int i = 0; i < n; i++)
			this->push_back(val);
	}

	void			push_back(const value_type & val)
	{
		int amount = 0;
		if (m_capacity <= m_size)
		{
			if (m_capacity == 0)
				amount = 1;
			else
				amount = m_capacity * 2;
			reserve(amount);
			m_capacity = amount;
		}
		m_alloc.construct(&m_data[m_size], val);
		m_size++;
	}

	void			pop_back(void)
	{
		if (m_size > 0)
		{
			m_size--;
			m_alloc.destroy(&m_data[m_size]);
		}
	}
	iterator insert (iterator position, const value_type& val)
	{
		difference_type diff = position - this->begin();

		this->insert(position, 1, val);
		return (iterator(this->begin() + diff));
	}

	void insert (iterator position, int n, const value_type& val)
	{
		difference_type const	idx = position - this->begin();
		difference_type const	old_end_idx = this->end() - this->begin();
		iterator				old_end, end;

		this->resize(this->m_size + n);

		end = this->end();
		position = this->begin() + idx;
		old_end = this->begin() + old_end_idx;
		while (old_end != position)
			*--end = *--old_end;
		while (n-- > 0)
			*position++ = val;
	}

	template <class InputIterator>
	void insert (iterator position, InputIterator first, typename ft::enable_if<ft::is_iterator<InputIterator>::value && (!ft::is_integral<InputIterator>::value), InputIterator>::type last)
	{
		difference_type const	idx = position - this->begin();
		difference_type const	old_end_idx = this->end() - this->begin();
		iterator				old_end, end;
		InputIterator			tmp = first;
		size_type				k = 0;

		while (tmp!= last)
		{
			k++;
			tmp++;
		}
		this->resize(this->m_size + k);

		end = this->end();
		position = this->begin() + idx;
		old_end = this->begin() + old_end_idx;
		while (old_end != position)
			*--end = *--old_end;
		while (first != last)
			*position++ = *first++;
	}
	iterator erase (iterator position)
	{
		return (erase(position, position + 1));
	}
	iterator erase (iterator first, iterator last)
	{
		iterator	tmp = first;
		iterator 	end = this->end();
		iterator	tmp2 = first;
		size_type	k = 0;

		while (tmp2!= last)
		{
			k++;
			tmp2++;
		}
		while (last != end)
		{
			*first = *last;
			++first;
			++last;
		}
		while (k-- > 0)
			pop_back();
		return (tmp);
	}

	void swap (vector& x)
	{
		size_type		tmpSize = this->m_size;
		size_type		tmpCapacity = this->m_capacity;
		pointer			tmpData = this->m_data;
		
		this->m_size = x.m_size;
		this->m_capacity = x.m_capacity;
		this->m_data = x.m_data;
		x.m_size = tmpSize;
		x.m_capacity = tmpCapacity;
		x.m_data = tmpData;
	}

	void clear()
	{
		while(this->m_size)
			pop_back();
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
		value_type		*m_data;
		size_type		m_size;
		size_type		m_capacity;
		allocator_type	m_alloc;
		

};

/***********************************************************************************************************************************
*															NON MEMBERS FUNCTIONS OVERLOADS														
***********************************************************************************************************************************/

	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if(lhs.size() != rhs.size())
			return false;
		for (size_t i = 0; i < lhs.size(); i++)
		{
			if (lhs[i] != rhs[i])
			{
				return false;
			}
		}
		return true;
	}

	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		size_t i = 0;
		for ( ;i < lhs.size(); i++)
		{
			if (i + 1 == rhs.size() || rhs[i] < lhs[i])
				return false;
			if (lhs[i] < rhs[i])
				return true;
		}
		if (i != rhs.size())
			return true;
		return (rhs[i] != lhs[i]);
	}


	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}


	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return ((rhs < lhs));
	}


	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs < rhs));

	}
	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		x.swap(y);
	}
}
#endif