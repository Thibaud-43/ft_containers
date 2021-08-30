#ifndef STACK_HPP
 #define STACK_HPP
#include <string>
#include <deque>
#include <limits>
#include <iostream>
#include <memory>

namespace ft
{

template <class T, class Container = std::deque<T> >
class stack
{

public:

/***********************************************************************************************************************************
*															TYPEDEF																
***********************************************************************************************************************************/
		typedef	T 			value_type;
		typedef Container	container_type;
		typedef size_t		size_type;

/***********************************************************************************************************************************
*															MEMBER FUNCTIONS														
***********************************************************************************************************************************/
		explicit stack (const container_type& ctnr = container_type()): m_container(ctnr)
		{
			
		}
		stack(stack const &other): m_container(other.container) 
		{

		}
		virtual ~stack() 
		{
			
		}

		stack &operator=(stack const &other) 
		{
			m_container = other.container;
			return (*this);
		}
		bool empty() const
		{
			return m_container.empty();
		}
		size_type size() const
		{
			return m_container.size();
		}
		value_type& top()
		{
			return m_container[m_container.size() - 1];
		}
		const value_type& top() const
		{
			return m_container[m_container.size() - 1];
		}
		void push (const value_type& val)
		{
			m_container.push_back(val);
		}
		void pop()
		{
			m_container.pop_back();
		}
/***********************************************************************************************************************************
*															PRIVATE ATTRIBUTES																
***********************************************************************************************************************************/
	
	private :
		size_type		m_size;
		container_type	m_container;

};

/***********************************************************************************************************************************
*															Non-member function overloads																
***********************************************************************************************************************************/

	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs == rhs);
	}
	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs != rhs);

	}
	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs < rhs);
	}
	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs <= rhs);
	}
	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs > rhs);
	}
	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs >= rhs);
	}
}
#endif