#ifndef Vector_H
 #define Vector_H

#include <string>
#include <iostream>
#include <memory>

namespace ft
{

template<typename vector>
class vectorIterator
{

public:
	typedef	typename vector::value_type						value_type;
	typedef	value_type*										pointer_type;
	typedef	value_type&										reference_type;

	vectorIterator(void): m_ptr(nullptr)
	{
	}
	vectorIterator(pointer_type ptr): m_ptr(ptr)
	{
	}
	vectorIterator(vectorIterator const & src): m_ptr(src.m_ptr)
	{
	}
	~vectorIterator()
	{
	}
	
	vectorIterator & operator= (vectorIterator const & rhs) 
	{
		m_ptr = rhs.m_ptr;
		return *this;
	}
	vectorIterator & operator++ (void) 
	{
		m_ptr++;
		return *this;
	}
	vectorIterator 	operator++ (int) 
	{
		vectorIterator	tmp(*this);
		m_ptr++;
		return tmp;
	}
	vectorIterator & operator-- (void) 
	{
		m_ptr--;
		return *this;
	}
	vectorIterator	operator-- (int) 
	{
		vectorIterator	tmp(*this);
		m_ptr--;
		return tmp;
	}
	reference_type	operator[](int index)
	{
		return *(m_ptr + index);
	}
	pointer_type	operator->()
	{
		return m_ptr;
	}
	reference_type	operator*()
	{
		return *m_ptr;
	}
	bool			operator== (const vectorIterator ptr) const
	{
		if (m_ptr == ptr.m_ptr)
			return true;
		return false;
	}
	bool			operator!= (const vectorIterator ptr) const
	{
		if (m_ptr == ptr.m_ptr)
			return false;
		return true;
	}

	private:
		pointer_type		m_ptr;
};


template<typename T, class Alloc = std::allocator<T> >
class vector
{

public:

/***********************************************************************************************************************************
*															TYPEDEF																
***********************************************************************************************************************************/

	typedef	size_t						size_type;
	typedef	T							value_type;
	typedef Alloc						allocator_type;
	typedef vectorIterator<vector <T> >	Iterator;

/***********************************************************************************************************************************
*															CONSTRUCTORS																
***********************************************************************************************************************************/

	explicit vector (const allocator_type& alloc = allocator_type()): m_data(nullptr), m_size(0), m_capacity(0), m_alloc(alloc)   
	{
	}

	explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): 
	m_alloc(alloc)
	{
		this->assign(n, val);
	}

	/*template <class InputIterator>
    vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type());

	vector (const vector& x);*/

/***********************************************************************************************************************************
*															DESTRUCTORS															
***********************************************************************************************************************************/

	~vector()
	{
		m_alloc.deallocate(m_data, m_capacity);
	};

/***********************************************************************************************************************************
*															MEMBERS FUNCTIONS																
***********************************************************************************************************************************/

	value_type		getValue(size_type i) const
	{
		return m_data[i];
	}

	size_type		capacity(void) const
	{
		return m_capacity;
	}

	size_type		size(void) const
	{
		return m_size;
	}

	void			push_back(const value_type & val)
	{
		if (m_capacity <= m_size)
			ReAlloc(m_capacity * 2);
		m_data[m_size] = val;
		m_size++;
	}

	void			pop_back(void)
	{
		if (m_size > 0)
		{
			m_size--;
			m_data[m_size].~value_type();
		}
	}

	template <class InputIterator>
	void assign (InputIterator first, InputIterator last)
	{
		static_cast<void>(first);
		static_cast<void>(last);
	}

	void assign (size_type n, const value_type& val)
	{
		m_alloc.deallocate(m_data, m_capacity);
		m_size = 0;
		m_capacity = n;
		m_data = m_alloc.allocate(m_capacity);
		for (size_t i = 0; i < n; i++)
			this->push_back(val);
	}

	Iterator	begin()
	{
		return Iterator(m_data);
	}

	Iterator	end()
	{
		return Iterator(m_data + m_size);
	}
	private:

/***********************************************************************************************************************************
*															PRIVATE ATTRIBUTES																
***********************************************************************************************************************************/

		T				*m_data;
		size_type		m_size;
		size_type		m_capacity;
		allocator_type	m_alloc;
		


/***********************************************************************************************************************************
*															PRIVATE MEMBERS FUNCTIONS																
***********************************************************************************************************************************/

		void	ReAlloc(size_type newCapacity)
		{
			T	*tmp;
			if (newCapacity < m_capacity)
				m_size = newCapacity;
			tmp = m_alloc.allocate(newCapacity);
			for (size_t i = 0; i < m_size; i++)
			{
				tmp[i] = m_data[i];
			}
			m_alloc.deallocate(m_data, m_capacity);
			m_data = tmp;
			m_capacity = newCapacity;
		}

};

template<typename T>
std::ostream	&	operator<<(std::ostream & o, vector<T> & rhs)
{
	o << std::endl << "[vector]\n\tcapacity:\t" << rhs.capacity() << "\n\tsize:\t\t" << rhs.size() << std::endl;
	o << "[values]" << std::endl;
	for (size_t i = 0; i < rhs.size(); i++)
	{
		o << "\tvector[" << i << "] = " << rhs.getValue(i) << std::endl;
	}
	return o;
}

}
#endif