#ifndef TestClass_H
 #define TestClass_H

#include <string>
#include <iostream>

class testClass
{
private:

public:
	size_t	m_data;
	testClass(/* args */);
	~testClass();
};

testClass::testClass(/* args */)
{
	std::cout << "create" << std::endl;
}

testClass::~testClass()
{
	std::cout << "destroy" << std::endl;
}

std::ostream	&	operator<<(std::ostream & o, testClass & rhs)
{
	o << rhs.m_data;
	return o;
}

#endif