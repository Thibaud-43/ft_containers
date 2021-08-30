/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <nboisde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 02:59:56 by nboisde           #+#    #+#             */
/*   Updated: 2021/08/18 02:59:58 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ReverseIterator_HPP
# define ReverseIterator_HPP

#include <IteratorTraits.hpp>
// https://en.cppreference.com/w/cpp/iterator/ReverseIterator/ReverseIterator

namespace ft
{
	template<class Iter>
	class ReverseIterator{
		public:
			typedef Iter											iterator_type;
			typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iter>::value_type			value_type;
			typedef typename ft::iterator_traits<Iter>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iter>::pointer				pointer;
			typedef typename ft::iterator_traits<Iter>::reference			reference;

			// constructors
			ReverseIterator() : _current(NULL){}

			// REGARDER SI ON PEUT PASSER LA FLECHE COMME FONCTION D'ACCES A _PTR, DOIT PROBABLEMENT MARCHER !!!!! PERMETTRAIT DE REPASSER _ptr en prive dans nos iterateurs.

			/*ICI on doit se poser sur l'element contenu en memoire juste avant. par exemple si on passe end en instance, on init avec le dernier element de notre data stucture.*/
			ReverseIterator(iterator_type x){//: _base(x){
				_current = iterator_type(x.Iter::operator->() - 1);
			}
			template <class U>
			ReverseIterator(const ReverseIterator<U>& other) : _current(other._current){}//, _base(other._base){}
			
			//destructors
			~ReverseIterator(){}

			//operator overload
			template< class U >
			ReverseIterator& operator=( const ReverseIterator<U>& other ){
				this->_current = other._current;
				this->_current._ptr = other._current.Iter::operator->();
				return *this;
			}
	
			//Member functions
			iterator_type base() const{return _current + 1;}

			reference operator*() const{return _current.Iter::operator*();}
			pointer operator->() const{return _current.Iter::operator->();}

			/*unspecified*/ typename Iter::value_type operator[](difference_type n){
				difference_type i = 0;
				ReverseIterator cpy = *this;
				while (i < n)
				{
					cpy++;
					i++;
				}
				return *(cpy);
			}
			ReverseIterator& operator++(){
				_current--;
				return *this;
			}
			ReverseIterator& operator--(){
				_current++;
				return *this;
			}
			ReverseIterator operator++( int ){
				return _current.Iter::operator--();
			}
			ReverseIterator operator--( int ){
				return _current.Iter::operator++();
			}
			ReverseIterator operator+( difference_type n ) const{
				//_current = _current - n;
				//return this;
				//_current.Iter::operator-(n);
				//return (*this);
				ReverseIterator it = *this;
				it += n;
				return it;
			}
			ReverseIterator operator-( difference_type n ) const{
				//_current = _current + n;
				//return this;
				//_current.Iter::operator+(n);
				ReverseIterator it = *this;
				it -= n;
				return it;//(*this);
			}
			ReverseIterator& operator+=( difference_type n ){
				_current -= n;
				return *this;
			}
			ReverseIterator& operator-=( difference_type n ){
				_current += n;
				return *this;
			}


		//protected:
			iterator_type _current;
			//iterator_type _base;
	};

	template< class Iterator1, class Iterator2 >
	bool operator==( const ft::ReverseIterator<Iterator1>& lhs, const ft::ReverseIterator<Iterator2>& rhs ){
		return (lhs._current == rhs._current);
	}
	template< class Iterator1, class Iterator2 >
	bool operator!=( const ft::ReverseIterator<Iterator1>& lhs, const ft::ReverseIterator<Iterator2>& rhs ){
		return (lhs._current != rhs._current);
	}
	template< class Iterator1, class Iterator2 >
	bool operator<( const ft::ReverseIterator<Iterator1>& lhs, const ft::ReverseIterator<Iterator2>& rhs ){
		return (lhs._current > rhs._current);
	}
	template< class Iterator1, class Iterator2 >
	bool operator<=( const ft::ReverseIterator<Iterator1>& lhs, const ft::ReverseIterator<Iterator2>& rhs ){
		return (lhs._current >= rhs._current);
	}
	template< class Iterator1, class Iterator2 >
	bool operator>( const ft::ReverseIterator<Iterator1>& lhs, const ft::ReverseIterator<Iterator2>& rhs ){
		return (lhs._current < rhs._current);
	}
	template< class Iterator1, class Iterator2 >
	bool operator>=( const ft::ReverseIterator<Iterator1>& lhs, const ft::ReverseIterator<Iterator2>& rhs ){
		return (lhs._current <= rhs._current);
	}
	template< class Iter >
	ReverseIterator<Iter> operator+( typename ReverseIterator<Iter>::difference_type n, const ReverseIterator<Iter>& it ){
		//return (it + n); ?
		return (it + n);
	}
	template< class Iterator >
	typename ReverseIterator<Iterator>::difference_type operator-( const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs ){
		//return (it - n); ?
		return (lhs._current - rhs._current);
	}

};

#endif
