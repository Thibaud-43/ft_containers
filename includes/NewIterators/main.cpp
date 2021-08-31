#include "VectorIterators.hpp"

int main(int argc, char const *argv[])
{
	ft::VectorIterator<int>	i;
	ft::ConstVectorIterator<int>	it;

	i = i + 1;
	it = it + 1;
	return 0;
}
