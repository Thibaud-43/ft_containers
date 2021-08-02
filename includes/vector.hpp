#ifndef Vector_H
 #define Vector_H

#include <ReverseIterator.hpp>
#include <string>
#include <limits>
#include <iostream>
#include <memory>



namespace ft
{

template<typename T>
class vectorIterator
{

public:
	typedef	T												value_type;
	typedef	value_type*										pointer_type;
	typedef	value_type&										reference_type;
	typedef value_type const * 								const_pointer;
	typedef value_type const & 								const_reference;

	vectorIterator(void): m_ptr(nullptr)
	{
	}
	vectorIterator(pointer_type ptr): m_ptr(ptr)
	{
	}
	vectorIterator(vectorIterator const & src): m_ptr(src.m_ptr)
	{
	}
	virtual ~vectorIterator()
	{
	}

	vectorIterator & operator= (vectorIterator const & rhs) 
	{
		m_ptr = rhs.m_ptr;
		return *this;
	}
	vectorIterator & operator++ (void) 
	{
		++this->m_ptr;
		return *this;
	}
	vectorIterator 	operator++ (int) 
	{
		vectorIterator	tmp(*this);
		++this->m_ptr;
		return tmp;
	}
	vectorIterator & operator-- (void) 
	{
		m_ptr--;
		return *this;
	}
	vectorIterator	operator--(int) 
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
		return (*this->m_ptr);
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
	vectorIterator &operator+=(int n)
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
	vectorIterator &operator-=(int n)
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
	vectorIterator operator+(int n) const
	{
		vectorIterator tmp(*this);
		tmp += n;
		return (tmp);
	};
	vectorIterator operator-(int n) const
	{
		vectorIterator tmp(*this);

		tmp -= n;
		return (tmp);
	};
	std::ptrdiff_t	operator-(vectorIterator & rhs) const
	{
		return m_ptr - rhs.m_ptr;
	}
	const_reference operator[](int nb) const 
	{
		return (*(this->m_ptr + nb));
	}
	const_reference operator*() const {
		return (*this->m_ptr);
	}
	const_pointer operator->() const {
		return (this->m_ptr);
	}
	bool operator<(vectorIterator const &other) const {
		return (this->m_ptr < other.m_ptr);
	}
	bool operator<=(vectorIterator const &other) const {
		return (this->m_ptr <= other.m_ptr);
	}
	bool operator>(vectorIterator const &other) const {
		return (this->m_ptr > other.m_ptr);
	}
	bool operator>=(vectorIterator const &other) const {
		return (this->m_ptr >= other.m_ptr);
	}
	protected:
		pointer_type		m_ptr;
};


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
	typedef vectorIterator<value_type>			iterator;
	typedef vectorIterator<value_type> 			const_iterator;
	typedef ReverseIterator<iterator> 			reverse_iterator;
	typedef ReverseIterator<const_iterator> 	const_reverse_iterator;
	typedef std::ptrdiff_t 						difference_type;
	typedef	size_t								size_type;



/***********************************************************************************************************************************
*															CONSTRUCTORS / DESTRUCTORS														
***********************************************************************************************************************************/

	explicit vector (const allocator_type& alloc = allocator_type()): m_data(nullptr), m_size(0), m_capacity(0), m_alloc(alloc)   
	{
	}

	explicit vector (int n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): 
	m_data(nullptr), m_size(0), m_capacity(0), m_alloc(alloc)
	{
		this->assign(n, val);
	}
	template <class InputIterator>
    vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()):
	m_data(nullptr), m_size(0), m_capacity(0), m_alloc(alloc)
	{
		this->assign(first, last);
	}

	vector (const vector & x): m_data(nullptr), m_size(0), m_capacity(0), m_alloc(x.m_alloc)
	{
		this->assign(x.begin(), x.end());
	}

	~vector()
	{
		m_alloc.deallocate(m_data, m_capacity);
	};

	vector &operator=(const vector &other)
	{
		m_size = 0;
		m_capacity = other.m_capacity;
		m_alloc = other.m_alloc;
		m_alloc.deallocate(m_data, m_capacity);
		m_data = m_alloc.allocate(m_capacity);
		for (iterator it = other.begin(); it != other.end(); it++)
		{
			this->push_back(*it);
		}
		return *this;
	}

/***********************************************************************************************************************************
*															ITERATORS																
***********************************************************************************************************************************/

	iterator	begin()
	{
		return iterator(m_data);
	}
	const_iterator	begin() const
	{
		return const_iterator(m_data);
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
				tmp[i] = m_data[i];
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
	void assign (InputIterator first, InputIterator last)
	{
		m_alloc.deallocate(m_data, m_capacity);
		m_capacity = last - first;
		m_size = 0;
		m_data = m_alloc.allocate(m_capacity);
		for (iterator it = first; it != last; it++)
		{
			this->push_back(*it);
		}
	}

	void assign (int n, const value_type& val)
	{
		m_alloc.deallocate(m_data, m_capacity);
		m_capacity = n;
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
	iterator insert (iterator position, const value_type& val)
	{
		size_type		i = 0;
		iterator		it = begin();

		while (it + i != position && i < m_size)
			i++;
		if (m_capacity < m_size + 1)
			reserve(m_size + 1);

		size_type	k = m_capacity - 1;

		while (k > i)
		{
			m_data[k] = m_data[k - 1];
			k--;
		}

		m_data[i] = val;
		m_size++;
		return (iterator(&m_data[i]));
	}

	void insert (iterator position, int n, const value_type& val)
	{
		while (n--)
			position = insert(position, val);
		
	}

	template <class InputIterator>
	void insert (iterator position, InputIterator first, InputIterator last)
	{
		while (first != last)
		{
			position = insert(position, (*first)) + 1;
			++first;
		}
	}
	/*iterator erase (iterator position)
	{

	}
	iterator erase (iterator first, iterator last)
	{

	}
	void swap (vector& x)
	{

	}
	void clear()
	{

	}*/

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
		T				*m_data;
		size_type		m_size;
		size_type		m_capacity;
		allocator_type	m_alloc;
		

};

/***********************************************************************************************************************************
*															NON MEMBERS FUNCTIONS OVERLOADS														
***********************************************************************************************************************************/

	/*template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{

	}

	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{

	}

	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{

	}


	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{

	}


	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{

	}


	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{

	}
	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	{

	}*/

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