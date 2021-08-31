#ifndef VectorIterator_HPP
# define VectorIterator_HPP

#include <string>
#include <limits>
#include <iostream>
#include <memory>
#include <ConstVectorIterator.hpp>

namespace ft
{
template<typename T>
class ConstVectorIterator;

template<typename T>
class VectorIterator
{

public:
	typedef	T												value_type;
	typedef	value_type*										pointer;
	typedef	value_type&										reference;
	typedef value_type const * 								const_pointer;
	typedef value_type const & 								const_reference;
	typedef std::ptrdiff_t									difference_type;
	typedef std::bidirectional_iterator_tag					iterator_category;

	VectorIterator(void): m_ptr(NULL)//, m_base(NULL)
	{
	}
	VectorIterator(pointer ptr): m_ptr(ptr)//, m_base(ptr)
	{
	}
	VectorIterator(const VectorIterator  & src): m_ptr(src.m_ptr)//, m_base(src.m_base)
	{
	}
	virtual ~VectorIterator()
	{
	}
	/*pointer	base() const
	{
		return m_base;
	}*/
	VectorIterator & operator= (VectorIterator const & rhs) 
	{
		m_ptr = rhs.m_ptr;
		return *this;
	}

	VectorIterator & operator=(ConstVectorIterator<value_type> const & rhs)
	{
		m_ptr = rhs.m_ptr;

		return *this;
	}
	VectorIterator & operator++ (void) 
	{
		++this->m_ptr;
		return *this;
	}
	VectorIterator 	operator++ (int) 
	{
		VectorIterator	tmp(*this);
		++this->m_ptr;
		return tmp;
	}
	VectorIterator & operator-- (void) 
	{
		m_ptr--;
		return *this;
	}
	VectorIterator	operator--(int) 
	{

		VectorIterator	tmp(*this);
		m_ptr--;
		return tmp;
	}
	reference	operator[](int index)
	{
		return *(m_ptr + index);
	}
	pointer	operator->()
	{
		return m_ptr;
	}
	reference	operator*()
	{
		return (*this->m_ptr);
	}
	bool			operator== (VectorIterator ptr) const
	{
		if (m_ptr == ptr.m_ptr)
			return true;
		return false;
	}
	bool			operator!= (const VectorIterator ptr) const
	{

		if (m_ptr == ptr.m_ptr)
			return false;
		return true;
	}
	bool			operator== (ConstVectorIterator<value_type> ptr) const
	{
		if (m_ptr == ptr.m_ptr)
			return true;
		return false;
	}

	bool operator==(pointer  rhs ){
        return (this->m_ptr == rhs);
    }
	bool operator!=(pointer  rhs ){
        return (this->m_ptr == rhs);
    }
	bool			operator!= (ConstVectorIterator<value_type> ptr) const
	{
		if (m_ptr == ptr.m_ptr)
			return false;
		return true;
	}
	VectorIterator &operator+=(difference_type n)
	{
		while (n < 0)
		{
			(*this)--;
			n++;
		}
		while (n > 0)
		{
			(*this)++;
			n--;
		}
		return (*this);
	};
	VectorIterator &operator-=(difference_type n)
	{

		while (n > 0)
		{
			operator--();	
			n--;
		}
		while (n < 0)
		{
			operator++();
			n++;
		}
		return (*this);
	};
	VectorIterator operator+(difference_type n) const
	{
		VectorIterator tmp(*this);
		tmp += n;
		return (tmp);
	};
	friend VectorIterator operator+(difference_type n, VectorIterator & rhs)
	{
		return (rhs + n);
	};
	friend const VectorIterator operator+(difference_type n, const VectorIterator & rhs)
	{
		return (rhs + n);
	};
	VectorIterator operator-(difference_type n) const
	{
		VectorIterator tmp(*this);

		tmp -= n;
		return (tmp);
	};
	std::ptrdiff_t	operator-(VectorIterator & rhs) const
	{
		return m_ptr - rhs.m_ptr;
	}
	std::ptrdiff_t	operator-(ConstVectorIterator<T> & rhs) const
	{
		return m_ptr - rhs.m_ptr;
	}
	std::ptrdiff_t	operator-(const VectorIterator & rhs) const
	{
		return m_ptr - rhs.m_ptr;
	}
	const_reference operator[](difference_type n) const 
	{
		return (*(this->m_ptr + n));
	}
	const_reference operator*() const 
	{
		return (*this->m_ptr);
	}
	const_pointer operator->() const 
	{
		return (this->m_ptr);
	}
	bool operator<(VectorIterator const &other) const 
	{
		return (this->m_ptr < other.m_ptr);
	}
	bool operator<=(VectorIterator const &other) const 
	{
		return (this->m_ptr <= other.m_ptr);
	}
	bool operator>(VectorIterator const &other) const 
	{
		return (this->m_ptr > other.m_ptr);
	}
	bool operator>=(VectorIterator const &other) const 
	{
		return (this->m_ptr >= other.m_ptr);
	}
	bool operator<(ConstVectorIterator<value_type> const &other) const 
	{
		return (this->m_ptr < other.m_ptr);
	}
	bool operator<=(ConstVectorIterator<value_type> const &other) const 
	{
		return (this->m_ptr <= other.m_ptr);
	}
	bool operator>(ConstVectorIterator<value_type> const &other) const 
	{
		return (this->m_ptr > other.m_ptr);
	}
	bool operator>=(ConstVectorIterator<value_type> const &other) const 
	{
		return (this->m_ptr >= other.m_ptr);
	}
	public:
		pointer		m_ptr;
		//pointer		m_base;
};
}

#endif