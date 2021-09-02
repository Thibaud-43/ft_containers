#ifndef ReverseIterators_H
 #define ReverseIterators_H

namespace	ft
{
	template<class Iterator>
	class ReverseIterator
	{
	protected:
		typedef Iterator	it;
		Iterator 			m_base;
	public:
		typedef Iterator							iterator_type;
		typedef typename it::difference_type		difference_type;
		typedef typename it::reference				reference;
		typedef typename it::pointer				pointer;

		ReverseIterator(void): m_base() { };;
		explicit ReverseIterator(Iterator x): m_base(x) { };;
		template <class U> ReverseIterator(const ReverseIterator<U> &u): m_base(u.base()) { };
		template <class U> ReverseIterator &operator=(const ReverseIterator<U> &u)
		{
			if (reinterpret_cast<const void *>(this) == reinterpret_cast<const void *>(&u))
				return (*this);
			this->m_base = u.base();
			return (*this);
		};
		Iterator base(void) const { return this->m_base; };



		reference			operator*(void) const { return (--it(this->m_base)).operator*(); };
		pointer				operator->(void) const { return &this->operator*(); };

		ReverseIterator	&operator++(void) { this->m_base.operator--(); return *this; };
		ReverseIterator	operator++(int) { return ReverseIterator(this->m_base.operator--(0)); };
		ReverseIterator	&operator--(void) { this->m_base.operator++(); return *this; };
		ReverseIterator	operator--(int) { return ReverseIterator(this->m_base.operator++(0)); };

		template <class U>
		difference_type		operator-(const ReverseIterator<U> &u) { return u.base().operator-(this->m_base); };
		ReverseIterator	operator+ (difference_type n) const { return ReverseIterator(this->m_base.operator-(n)); };
		ReverseIterator	&operator+=(difference_type n) { this->m_base.operator-=(n); return *this; };
		ReverseIterator	operator- (difference_type n) const { return ReverseIterator(this->m_base.operator+(n)); };
		ReverseIterator	&operator-=(difference_type n) { this->m_base.operator+=(n); return *this; };
		reference			operator[](difference_type n) const { return *this->operator+(n); };

		friend ReverseIterator	operator+(difference_type n, const ReverseIterator &rhs)
			{ return rhs.operator+(n); };

		template <class U> bool	operator==(const ReverseIterator<U> &rhs) const { return this->m_base.operator==(rhs.base()); };
		template <class U> bool	operator!=(const ReverseIterator<U> &rhs) const { return this->m_base.operator!=(rhs.base()); };
		template <class U> bool	operator< (const ReverseIterator<U> &rhs) const { return this->m_base.operator> (rhs.base()); };
		template <class U> bool	operator<=(const ReverseIterator<U> &rhs) const { return this->m_base.operator>=(rhs.base()); };
		template <class U> bool	operator> (const ReverseIterator<U> &rhs) const { return this->m_base.operator< (rhs.base()); };
		template <class U> bool	operator>=(const ReverseIterator<U> &rhs) const { return this->m_base.operator<=(rhs.base()); };
	};
};

#endif