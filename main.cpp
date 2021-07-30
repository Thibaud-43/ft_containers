#include <vector.hpp>
#include <testClass.hpp>

using namespace ft;

int main(void)
{
	vector<size_t>	vec(10);
	vector<size_t>	vec2;
	for (size_t i = 0; i < 25; i++)
		vec.push_back(i);
	std::cout << vec;
	vec.assign(static_cast<size_t>(5), 10);
	std::cout << vec;

	for(ft::vector<size_t>::Iterator it = vec.begin(); it != vec.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	return 0;
}
