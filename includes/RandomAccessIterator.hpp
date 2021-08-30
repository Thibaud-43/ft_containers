#ifndef RandomAccessIterator_H
 #define RandomAccessIterator_H

template<typename T>
class RandomAccessIterator
{
	public:
		typedef	T												value_type;
		typedef	value_type*										pointer;
		typedef	value_type&										reference;
		typedef value_type const * 								const_pointer;
		typedef value_type const & 								const_reference;
		typedef std::ptrdiff_t									difference_type;
		typedef std::forward_iterator_tag						iterator_category;

		RandomAccessIterator(void): m_ptr(NULL)
		{
		}
		/*RandomAccessIterator(pointer ptr): m_ptr(ptr)
		{
		}*/
		RandomAccessIterator(const RandomAccessIterator & src): m_ptr(src.m_ptr)
		{
		}
		RandomAccessIterator & operator= (RandomAccessIterator const & rhs) 
		{
			m_ptr = rhs.m_ptr;
			return *this;
		}
		bool			operator== (const RandomAccessIterator ptr) const
		{
			if (m_ptr == ptr.m_ptr)
				return true;
			return false;
		}
		bool			operator!= (const RandomAccessIterator ptr) const
		{
			if (m_ptr == ptr.m_ptr)
				return false;
			return true;
		}
		pointer	operator->()
		{
			return m_ptr;
		}
		~RandomAccessIterator();

	protected:
		pointer		m_ptr;
};


#endif