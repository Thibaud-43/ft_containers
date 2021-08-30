#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP

#include <VectorIterator.hpp>
#include <ConstVectorIterator.hpp>
class vectorIterator;
class mapIterator;

namespace ft
{
template<typename T>
class ReverseIterator : public VectorIterator<T>
{

public:
	typedef	typename VectorIterator<T>::value_type				value_type;
	typedef	typename VectorIterator<T>::pointer					pointer;
	typedef	typename VectorIterator<T>::reference				reference;
	typedef typename VectorIterator<T>::const_pointer 			const_pointer;
	typedef typename VectorIterator<T>::const_reference			const_reference;
	typedef typename VectorIterator<T>::iterator_category		iterator_category;



	ReverseIterator(void): VectorIterator<T>()
	{
	}
	ReverseIterator(ReverseIterator const & src):VectorIterator<T>(src.m_ptr)
	{
	}
    ReverseIterator(VectorIterator<T> const & iterator):VectorIterator<T>(iterator)
    {

    }
	
	~ReverseIterator()
	{
	}
	ReverseIterator	base() const
	{
		VectorIterator<T>	tmp(*this);
		return tmp - 1;
	}
	reference	operator*()
	{
        VectorIterator<T>    tmp(*this);
		return (*--tmp);
	}
	const_reference operator*() const 
    {
        VectorIterator<T>    tmp(*this);
		return (*--tmp);
	}
	pointer	operator->()
	{
        VectorIterator<T>    tmp(*this);
		return (&*--tmp);
	}

	const_pointer operator->() const 
    {
        VectorIterator<T>    tmp(*this);
		return (&*--tmp);
	}

	VectorIterator<T> & operator++ (void) 
	{
		return (this->VectorIterator<T>::operator--());
	}
	ReverseIterator 	operator++ (int) 
	{
        VectorIterator<T>    tmp(*this);
        operator++();
		return (tmp);
	}

	VectorIterator<T> & operator-- (void) 
	{
		return (this->VectorIterator<T>::operator++());
	}
	ReverseIterator	operator--(int) 
	{
        VectorIterator<T>    tmp(*this);
        operator--();
		return (tmp);
	}

	template< class Iterator1, class Iterator2 >
    friend bool operator==( const ft::ReverseIterator<Iterator1>& lhs, const ft::ReverseIterator<Iterator2>& rhs ){
        return (lhs.m_ptr == rhs.m_ptr);
    }

    template< class Iterator1, class Iterator2 >
    friend bool operator!=( const ft::ReverseIterator<Iterator1>& lhs, const ft::ReverseIterator<Iterator2>& rhs ){
        return (lhs.m_ptr != rhs.m_ptr);
    }
    template< class Iterator1, class Iterator2 >
    friend bool operator<( const ft::ReverseIterator<Iterator1>& lhs, const ft::ReverseIterator<Iterator2>& rhs ){
        return (lhs.m_ptr > rhs.m_ptr);
    }
    template< class Iterator1, class Iterator2 >
    friend bool operator<=( const ft::ReverseIterator<Iterator1>& lhs, const ft::ReverseIterator<Iterator2>& rhs ){
        return (lhs.m_ptr >= rhs.m_ptr);
    }
    template< class Iterator1, class Iterator2 >
    friend bool operator>( const ft::ReverseIterator<Iterator1>& lhs, const ft::ReverseIterator<Iterator2>& rhs ){
        return (lhs.m_ptr < rhs.m_ptr);
    }
    template< class Iterator1, class Iterator2 >
    friend bool operator>=( const ft::ReverseIterator<Iterator1>& lhs, const ft::ReverseIterator<Iterator2>& rhs ){
        return (lhs.m_ptr <= rhs.m_ptr);
    }
    template< class Iter >
    friend ReverseIterator<Iter> operator+( typename ReverseIterator<Iter>::difference_type n, const ReverseIterator<Iter>& it ){
        //return (it + n); ?
        return (it + n);
    }

};

template<typename T>
class ConstReverseIterator : public ConstVectorIterator<T>
{

public:
	typedef	typename ConstVectorIterator<T>::value_type				value_type;
	typedef	typename ConstVectorIterator<T>::pointer					pointer;
	typedef	typename ConstVectorIterator<T>::reference				reference;
	typedef typename ConstVectorIterator<T>::const_pointer 			const_pointer;
	typedef typename ConstVectorIterator<T>::const_reference			const_reference;
	typedef typename ConstVectorIterator<T>::iterator_category		iterator_category;



	ConstReverseIterator(void): ConstVectorIterator<T>()
	{
	}
	ConstReverseIterator(ConstReverseIterator const & src):ConstVectorIterator<T>(src.m_ptr)
	{
	}
    ConstReverseIterator(ReverseIterator<T> const & iterator):ConstVectorIterator<T>(iterator.base())
    {

    }
	ConstReverseIterator(ConstVectorIterator<T> const & iterator):ConstVectorIterator<T>(iterator.base())
    {

    }
	ConstReverseIterator(VectorIterator<T> const & iterator):ConstVectorIterator<T>(iterator.base())
    {

    }
	~ConstReverseIterator()
	{
	}
	ConstReverseIterator	base() const
	{
		ConstVectorIterator<T>	tmp(*this);
		return tmp - 1;
	}
	ConstVectorIterator<T>	&	operator=(VectorIterator<T> & rhs)
	{
		this->m_ptr = rhs.base();
		return *this;
	}
	ConstVectorIterator<T> & operator++ (void) 
	{
		return (this->ConstVectorIterator<T>::operator--());
	}
	ConstReverseIterator 	operator++ (int) 
	{
        ConstVectorIterator<T>    tmp(*this);
        operator++();
		return (tmp);
	}

	ConstVectorIterator<T> & operator-- (void) 
	{
		return (this->ConstVectorIterator<T>::operator++());
	}
	ConstReverseIterator	operator--(int) 
	{
        ConstVectorIterator<T>    tmp(*this);
        operator--();
		return (tmp);
	}

	template< class Iterator1, class Iterator2 >
    friend bool operator==( const ft::ConstReverseIterator<Iterator1>& lhs, const ft::ConstReverseIterator<Iterator2>& rhs ){
        return (lhs.m_ptr == rhs.m_ptr);
    }

    template< class Iterator1, class Iterator2 >
    friend bool operator!=( const ft::ConstReverseIterator<Iterator1>& lhs, const ft::ConstReverseIterator<Iterator2>& rhs ){
        return (lhs.m_ptr != rhs.m_ptr);
    }
    template< class Iterator1, class Iterator2 >
    friend bool operator<( const ft::ConstReverseIterator<Iterator1>& lhs, const ft::ConstReverseIterator<Iterator2>& rhs ){
        return (lhs.m_ptr > rhs.m_ptr);
    }
    template< class Iterator1, class Iterator2 >
    friend bool operator<=( const ft::ConstReverseIterator<Iterator1>& lhs, const ft::ConstReverseIterator<Iterator2>& rhs ){
        return (lhs.m_ptr >= rhs.m_ptr);
    }
    template< class Iterator1, class Iterator2 >
    friend bool operator>( const ft::ConstReverseIterator<Iterator1>& lhs, const ft::ConstReverseIterator<Iterator2>& rhs ){
        return (lhs.m_ptr < rhs.m_ptr);
    }
    template< class Iterator1, class Iterator2 >
    friend bool operator>=( const ft::ConstReverseIterator<Iterator1>& lhs, const ft::ConstReverseIterator<Iterator2>& rhs ){
        return (lhs.m_ptr <= rhs.m_ptr);
    }
    template< class Iter >
    friend ConstReverseIterator<Iter> operator+( typename ConstReverseIterator<Iter>::difference_type n, const ConstReverseIterator<Iter>& it ){
        //return (it + n); ?
        return (it + n);
    }

};
};
#endif