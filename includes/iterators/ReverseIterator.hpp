#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP


class vectorIterator;
class mapIterator;

namespace ft
{

template<typename Iterator>
class ReverseIterator : public Iterator
{

public:
	typedef	typename Iterator::value_type				value_type;
	typedef	typename Iterator::pointer					pointer;
	typedef	typename Iterator::reference				reference;
	typedef typename Iterator::const_pointer 			const_pointer;
	typedef typename Iterator::const_reference			const_reference;
	typedef typename Iterator::iterator_category		iterator_category;


	ReverseIterator(void): Iterator()
	{
	}
	ReverseIterator(ReverseIterator const & src):Iterator(src.m_ptr)
	{
	}
    ReverseIterator(Iterator const & iterator):Iterator(iterator)
    {

    }
	~ReverseIterator()
	{
	}
	reference	operator*()
	{
        Iterator    tmp(*this);
		return (*--tmp);
	}
	const_reference operator*() const 
    {
        Iterator    tmp(*this);
		return (*--tmp);
	}
	pointer	operator->()
	{
        Iterator    tmp(*this);
		return (&*--tmp);
	}

	const_pointer operator->() const 
    {
        Iterator    tmp(*this);
		return (&*--tmp);
	}

	Iterator & operator++ (void) 
	{
		return (this->Iterator::operator--());
	}
	ReverseIterator 	operator++ (int) 
	{
        Iterator    tmp(*this);
        operator++();
		return (tmp);
	}

	Iterator & operator-- (void) 
	{
		return (this->Iterator::operator++());
	}
	ReverseIterator	operator--(int) 
	{
        Iterator    tmp(*this);
        operator--();
		return (tmp);
	}
};
};
#endif