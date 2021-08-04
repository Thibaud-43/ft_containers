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
		std::cout << it->first << std::endl;
		clock.printStdTime();
	}
	{
		clock.setBeginFt();
		using namespace ft;
		map<std::string, int>	test2;
		map<int, int>	test;
		test.insert(make_pair(10, 10));
		test2.insert(make_pair("test", 10));
		test2.insert(make_pair("test1", 10));
		test2.insert(make_pair("test4", 10));
		test2.insert(make_pair("test5", 10));
		map<std::string, int>::iterator it = test2.begin();
		std::cout << it->first << std::endl;
		clock.printFtTime();
	}
	std::cout << std::endl << std::endl;
	return 0;
}
