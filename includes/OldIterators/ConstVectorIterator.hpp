#ifndef ConstVectorIterator_HPP
# define ConstVectorIterator_HPP

#include <string>
#include <limits>
#include <iostream>
#include <memory>
#include <VectorIterator.hpp>

namespace ft
{
template<typename T>
class VectorIterator;
template<typename T>
class ConstVectorIterator//: public VectorIterator <T>
{

public:
	typedef	T												value_type;
	typedef	value_type*										pointer;
	typedef	value_type&										reference;
	typedef value_type const * 								const_pointer;
	typedef value_type const & 								const_reference;
	typedef std::ptrdiff_t									difference_type;
	typedef std::forward_iterator_tag						iterator_category;

	ConstVectorIterator(void): m_ptr(NULL)//, m_base(NULL)
	{
	}
	ConstVectorIterator(pointer ptr): m_ptr(ptr)//, m_base(ptr)
	{
	}
	ConstVectorIterator(const ConstVectorIterator & src): m_ptr(src.m_ptr)//, m_base(src.m_base)
	{
	}
	ConstVectorIterator(VectorIterator<value_type> const  & src): m_ptr(src.m_ptr)//, m_base(src.m_base)
	{
	}
	virtual ~ConstVectorIterator()
	{
	}
/*pointer	base() const
	{
		return m_base;
	}*/
	ConstVectorIterator & operator= (ConstVectorIterator const  & rhs) 
	{
		m_ptr = rhs.m_ptr;
		return *this;
	}
	ConstVectorIterator & operator= (VectorIterator<value_type> const  & rhs) 
	{
		m_ptr = rhs.m_ptr;
		return *this;
	}
	ConstVectorIterator & operator++ (void) 
	{
		++this->m_ptr;
		return *this;
	}
	ConstVectorIterator 	operator++ (int) 
	{
		ConstVectorIterator	tmp(*this);
		++this->m_ptr;
		return tmp;
	}
	ConstVectorIterator & operator-- (void) 
	{
		m_ptr--;
		return *this;
	}
	ConstVectorIterator	operator--(int) 
	{

		ConstVectorIterator	tmp(*this);
		m_ptr--;
		return tmp;
	}
	/*reference	operator[](int index)
	{
		return *(m_ptr + index);
	}*/
	/*pointer	operator->()
	{
		return m_ptr;
	}*/
	/*reference	operator*()
	{
		return (*this->m_ptr);
	}*/
	bool			operator== (const ConstVectorIterator ptr) const
	{
		if (m_ptr == ptr.m_ptr)
			return true;
		return false;
	}
	bool			operator!= (const ConstVectorIterator ptr) const
	{
		if (m_ptr == ptr.m_ptr)
			return false;
		return true;
	}
	bool			operator== (VectorIterator<value_type> const ptr) const
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
	bool			operator!= (VectorIterator<value_type> const ptr) const
	{
		if (m_ptr == ptr.m_ptr)
			return false;
		return true;
	}
	ConstVectorIterator &operator+=(difference_type n)
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
	ConstVectorIterator &operator-=(difference_type n)
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
	ConstVectorIterator operator+(difference_type n) const
	{
		ConstVectorIterator tmp(*this);
		tmp += n;
		return (tmp);
	};

	friend ConstVectorIterator operator+(difference_type n, ConstVectorIterator & rhs)
	{
		return (rhs + n);
	};

	ConstVectorIterator operator-(difference_type n) const
	{
		ConstVectorIterator tmp(*this);

		tmp -= n;
		return (tmp);
	};
	std::ptrdiff_t	operator-(ConstVectorIterator & rhs) const
	{
		return m_ptr - rhs.m_ptr;
	}
	std::ptrdiff_t	operator-(const ConstVectorIterator & rhs) const
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
	bool operator<(ConstVectorIterator const &other) const 
	{
		return (this->m_ptr < other.m_ptr);
	}
	bool operator<=(ConstVectorIterator const &other) const 
	{
		return (this->m_ptr <= other.m_ptr);
	}
	bool operator>(ConstVectorIterator const &other) const 
	{
		return (this->m_ptr > other.m_ptr);
	}
	bool operator>=(ConstVectorIterator const &other) const 
	{
		return (this->m_ptr >= other.m_ptr);
	}
	bool operator<(VectorIterator<value_type> const &other) const 
	{
		return (this->m_ptr < other.m_ptr);
	}
	bool operator<=(VectorIterator<value_type> const &other) const 
	{
		return (this->m_ptr <= other.m_ptr);
	}
	bool operator>(VectorIterator<value_type> const &other) const 
	{
		return (this->m_ptr > other.m_ptr);
	}
	bool operator>=(VectorIterator<value_type> const &other) const 
	{
		return (this->m_ptr >= other.m_ptr);
	}
	public:
		pointer		m_ptr;
		//pointer		m_base;
};
}

#endif