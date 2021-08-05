#include <map.hpp>
#include <map>
#include <ctime>

class Time
{
private:
	clock_t		m_begin_std;
	clock_t		m_end_std;
	clock_t		m_begin_ft;
	clock_t		m_end_ft;
public:
	Time(/* args */){};
	~Time(){};

	void	setBeginStd(void)
	{
		m_begin_std = clock();
	}
	void	setBeginFt(void)
	{
		m_begin_ft = clock();
	}
	void	printStdTime(void)
	{
		m_end_std = clock();
		std::cout << "Total time elapsed: " << m_end_std - m_begin_std << std::endl << std::endl;
	}

	void	printFtTime(void)
	{
		m_end_ft = clock();
		if (m_end_ft - m_begin_ft < 20 * (m_end_std - m_begin_std))
		{
			std::cout << "\033[1;32m";
			std::cout << "Total time elapsed: " << m_end_ft - m_begin_ft << std::endl << std::endl;
			std::cout << "\033[0m\n";
		}
		else
		{
			std::cout << "\033[1;31m";
			std::cout << "Total time elapsed: " << m_end_ft - m_begin_ft << std::endl << std::endl;
			std::cout << "\033[0m\n";
		}
	}
};


int main(void)
{
	Time	clock;

	std::cout << "TEST CONSTRUCTORS" << std::endl << std::endl;
	{
		clock.setBeginStd();
		std::map<std::string, int>	test2;
		std::map<int, int>	test;
		test.insert(std::make_pair(10, 10));
		test2.insert(std::make_pair("test", 10));
		test2.insert(std::make_pair("test1", 10));
		test2.insert(std::make_pair("test4", 10));
		test2.insert(std::make_pair("test5", 10));
		std::map<std::string, int>::iterator it = test2.begin();
		std::map<std::string, int>::iterator it2 = test2.end();
		it2--;
		for (;it2 != it; it2--)
		{
			std::cout << it2->first << std::endl;
		}
		it2 = test2.end();
		for ( ;it != it2; it++)
		{
			std::cout << it->first << std::endl;
		}
		clock.printStdTime();
	}
	{
		clock.setBeginFt();
		using namespace ft;
		map<std::string, int>	test2;
		test2.insert(make_pair("test", 10));
		test2.insert(make_pair("test1", 10));
		test2.insert(make_pair("test4", 10));
		test2.insert(make_pair("test5", 10));

		map<std::string, int>::iterator it = test2.begin();
		map<std::string, int>::iterator it2 = test2.end();
		it2--;
		for (;it2 != it; it2--)
		{
			std::cout << it2->first << std::endl;
		}
		it2 = test2.end();
		for ( ;it != it2; it++)
		{
			std::cout << it->first << std::endl;
		}
		
		clock.printFtTime();
	}
	std::cout << std::endl << std::endl;

	std::cout << "TEST INSER" << std::endl << std::endl;
	{
		clock.setBeginStd();
		std::map<char,int> mymap;

		// first insert function version (single parameter):
		mymap.insert ( std::pair<char,int>('a',100) );
		mymap.insert ( std::pair<char,int>('z',200) );

		std::pair<std::map<char,int>::iterator,bool> ret;
		ret = mymap.insert ( std::pair<char,int>('z',500) );
		if (ret.second==false) {
			std::cout << "element 'z' already existed";
			std::cout << " with a value of " << ret.first->second << '\n';
		}
		clock.printStdTime();
	}
	{
		clock.setBeginFt();
		using namespace ft;

		map<char,int> mymap;

		// first insert function version (single parameter):
		mymap.insert ( pair<char,int>('a',100) );
		mymap.insert ( pair<char,int>('z',200) );

		pair<map<char,int>::iterator,bool> ret;
		ret = mymap.insert ( pair<char,int>('z',500) );
		if (ret.second==false) {
			std::cout << "element 'z' already existed";
			std::cout << " with a value of " << ret.first->second << '\n';
		}
		clock.printFtTime();
	}

	std::cout << "TEST" << std::endl << std::endl;
	{
		clock.setBeginStd();
		std::map<char,int> mymap;

		// first insert function version (single parameter):
		mymap.insert ( std::pair<char,int>('a',100) );
		mymap.insert ( std::pair<char,int>('z',200) );
		std::map<char, int>::reverse_iterator it = mymap.rbegin();
		std::map<char, int>::reverse_iterator it2 = mymap.rend();
		
		for (; it != it2; it++)
		{
			std::cout << it->first << std::endl;
		}
		
		clock.printStdTime();
	}
	{
		clock.setBeginFt();
		using namespace ft;
		map<char,int> mymap;

		// first insert function version (single parameter):
		mymap.insert ( pair<char,int>('a',100) );
		mymap.insert ( pair<char,int>('z',200) );
		map<char, int>::reverse_iterator it = mymap.rbegin();
		map<char, int>::reverse_iterator it2 = mymap.rend();

		for (; it != it2; it++)
		{
			std::cout << it->first << std::endl;
		}

		clock.printStdTime();
		clock.printFtTime();
	}
	std::cout << std::endl << std::endl;
	return 0;
}
