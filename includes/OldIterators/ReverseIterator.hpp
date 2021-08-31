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
	typedef std::ptrdiff_t										difference_type;
	typedef typename VectorIterator<T>::iterator_category		iterator_category;
	VectorIterator<T>	m_base;


	ReverseIterator(void): VectorIterator<T>(), m_base()
	{
	}
	ReverseIterator(ReverseIterator const & src):VectorIterator<T>(src), m_base(src.m_base)
	{
	}
    ReverseIterator(VectorIterator<T> const & iterator):VectorIterator<T>(iterator), m_base(iterator)
    {
	
    }
	
	~ReverseIterator()
	{
	}
	VectorIterator<T>	base() const
	{
		return m_base;
	}
	reference	operator*()
	{
        VectorIterator<T>    tmp(m_base);
		return (*(--tmp));
	}
	const_reference operator*() const 
    {
        VectorIterator<T>    tmp(m_base);
		return (*(--tmp));
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
	ReverseIterator	&operator++(void) 
	{
		 this->m_base.operator--(); return *this; 
	}
	ReverseIterator	operator++(int) 
	{
		 return ReverseIterator(this->m_base.operator--(0)); 
	}
	ReverseIterator	&operator--(void) 
	{
		 this->m_base.operator++(); return *this; 
	}
	ReverseIterator	operator--(int) 
	{
		 return ReverseIterator(this->m_base.operator++(0)); 
	}
	template <class U>
	difference_type		operator-(const ReverseIterator<U> &u) 
	{
		 return u.base().operator-(this->m_base); 
	}
	ReverseIterator	operator+ (difference_type n) const 
	{
		 return ReverseIterator(this->m_base.operator-(n)); 
	}
	ReverseIterator	&operator+=(difference_type n) 
	{
		 this->m_base.operator-=(n); 
		 return *this; 
	}
	ReverseIterator	operator- (difference_type n) const 
	{
		 return ReverseIterator(this->m_base.operator+(n)); 
	}
	ReverseIterator	&operator-=(difference_type n) 
	{
		 this->m_base.operator+=(n); return *this; 
	}
	reference			operator[](difference_type n) const 
	{
		 return *this->operator+(n); 
	}

		friend ReverseIterator	operator+(difference_type n, const ReverseIterator &rhs)
			{ return rhs.operator+(n); };

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

};

/*template<typename T>
class ConstReverseIterator : public ConstVectorIterator<T>
{

public:
	typedef	typename ConstVectorIterator<T>::value_type				value_type;
	typedef	typename ConstVectorIterator<T>::pointer					pointer;
	typedef	typename ConstVectorIterator<T>::reference				reference;
	typedef typename ConstVectorIterator<T>::const_pointer 			const_pointer;
	typedef typename ConstVectorIterator<T>::const_reference			const_reference;
	typedef typename ConstVectorIterator<T>::iterator_category		iterator_category;

	ConstVectorIterator<T>	m_base;

	ConstReverseIterator(void): ConstVectorIterator<T>()
	{
	}
	ConstReverseIterator(ConstReverseIterator const & src):ConstVectorIterator<T>(src.m_ptr), m_base(src.m_base)
	{
	}
    ConstReverseIterator(ReverseIterator<T> const & iterator):ConstVectorIterator<T>(iterator), m_base(iterator.m_base)
    {

    }
	ConstReverseIterator(ConstVectorIterator<T> const & iterator):ConstVectorIterator<T>(iterator), m_base(iterator)
    {

    }
	ConstReverseIterator(VectorIterator<T> const & iterator):ConstVectorIterator<T>(iterator), m_base(iterator)
    {

    }
	~ConstReverseIterator()
	{
	}

	ConstVectorIterator<T>	base() const
	{
		return m_base;
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

};*/
template<typename T>
class ConstReverseIterator : public ConstVectorIterator<T>
{

public:
	typedef	typename ConstVectorIterator<T>::value_type				value_type;
	typedef	typename ConstVectorIterator<T>::pointer					pointer;
	typedef	typename ConstVectorIterator<T>::reference				reference;
	typedef typename ConstVectorIterator<T>::const_pointer 			const_pointer;
	typedef typename ConstVectorIterator<T>::const_reference			const_reference;
	typedef std::ptrdiff_t										difference_type;
	typedef typename ConstVectorIterator<T>::iterator_category		iterator_category;
	ConstVectorIterator<T>	m_base;


	ConstReverseIterator(void): ConstVectorIterator<T>()
	{
	}
	ConstReverseIterator(ConstReverseIterator const & src):ConstVectorIterator<T>(src.m_ptr), m_base(src.m_base)
	{
	}
    ConstReverseIterator(ReverseIterator<T> const & iterator):ConstVectorIterator<T>(iterator), m_base(iterator.m_base)
    {

    }
	ConstReverseIterator(ConstVectorIterator<T> const & iterator):ConstVectorIterator<T>(iterator), m_base(iterator)
    {

    }
	ConstReverseIterator(VectorIterator<T> const & iterator):ConstVectorIterator<T>(iterator), m_base(iterator)
    {

    }
	
	~ConstReverseIterator()
	{
	}
	ConstVectorIterator<T>	base() const
	{
		return m_base;
	}

	ConstReverseIterator	&operator++(void) 
	{
		 this->m_base.operator--(); return *this; 
	}
	ConstReverseIterator	operator++(int) 
	{
		 return ConstReverseIterator(this->m_base.operator--(0)); 
	}
	ConstReverseIterator	&operator--(void) 
	{
		 this->m_base.operator++(); return *this; 
	}
	ConstReverseIterator	operator--(int) 
	{
		 return ConstReverseIterator(this->m_base.operator++(0)); 
	}

	difference_type		operator-(const ConstReverseIterator<T> &u) 
	{
		 return u.base().operator-(this->m_base); 
	}

	difference_type		operator-(const ReverseIterator<T> &u) 
	{

		 return u.base().operator-(this->m_base); 
	}

	ConstReverseIterator	operator+ (difference_type n) const 
	{
		 return ConstReverseIterator(this->m_base.operator-(n)); 
	}

	ConstReverseIterator	&operator+=(difference_type n) 
	{
		 this->m_base.operator-=(n); 
		 return *this; 
	}
	ConstReverseIterator	operator- (difference_type n) const 
	{
		 return ConstReverseIterator(this->m_base.operator+(n)); 
	}
	ConstReverseIterator	&operator-=(difference_type n) 
	{
		 this->m_base.operator+=(n); 
		 return *this; 
	}
	reference			operator[](difference_type n) const 
	{
		 return *this->operator+(n); 
	}

		friend ConstReverseIterator	operator+(difference_type n, const ConstReverseIterator &rhs)
			{ return rhs.operator+(n); };

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
};

};
#endif