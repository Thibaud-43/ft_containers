#include <stack.hpp>
#include <ctime>
#include <string>
#include <iostream>
#include <fstream> 


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
        std::cout << "Total time elapsed: " << m_end_ft - m_begin_ft << std::endl << std::endl;
	}
};

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

int main(void)
{
	Time	clock;
	std::ofstream fs;
  	fs.open ("results/ft_stack.txt");
	if (!fs.is_open())
    {    
        std::cout << "Error with file" << std::endl;
    }
	fs << "TEST CONSTRUCTORS" << std::endl << std::endl;
	{
		clock.setBeginStd();
		clock.printStdTime();
	}
	fs << std::endl << std::endl;
	fs.close();
	return 0;
}
