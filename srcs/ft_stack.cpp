#include <stack.hpp>
#include <ctime>
#include <string>
#include <iostream>
#include <fstream> 
#include <vector.hpp> 


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
		std::deque<int> mydeque (3,100);          // deque with 3 elements
		ft::vector<int> myvector (2,200);        // vector with 2 elements

		ft::stack<int> first;                    // empty stack
		ft::stack<int> second (mydeque);         // stack initialized to copy of deque

		ft::stack<int,ft::vector<int> > third;  // empty stack using vector
		ft::stack<int,ft::vector<int> > fourth (myvector);

		fs << "size of first: " << first.size() << '\n';
		fs << "size of second: " << second.size() << '\n';
		fs << "size of third: " << third.size() << '\n';
		fs << "size of fourth: " << fourth.size() << '\n';
		clock.printStdTime();
	}
	fs << std::endl << std::endl;
	
	fs << "TEST EMPTY" << std::endl << std::endl;
	{
		clock.setBeginStd();
		ft::stack<int> mystack;
		int sum (0);

		for (int i=1;i<=10;i++) mystack.push(i);

		while (!mystack.empty())
		{
			sum += mystack.top();
			mystack.pop();
		}

		fs << "total: " << sum << '\n';

		clock.printStdTime();
	}
	fs << std::endl << std::endl;
	fs << "TEST SIZE" << std::endl << std::endl;
	{
		clock.setBeginStd();
		ft::stack<int> myints;
		fs << "0. size: " << myints.size() << '\n';

		for (int i=0; i<5; i++) myints.push(i);
			fs << "1. size: " << myints.size() << '\n';

		myints.pop();
		fs << "2. size: " << myints.size() << '\n';

		clock.printStdTime();
	}
	fs << std::endl << std::endl;
	fs << "TEST TOP" << std::endl << std::endl;
	{
		clock.setBeginStd();
		ft::stack<int> mystack;

		mystack.push(10);
		mystack.push(20);

		mystack.top() -= 5;

		fs << "mystack.top() is now " << mystack.top() << '\n';

		clock.printStdTime();
	}
	fs << std::endl << std::endl;
		fs << "TEST PUSH" << std::endl << std::endl;
	{
		clock.setBeginStd();
		ft::stack<int> mystack;

		for (int i=0; i<5; ++i) mystack.push(i);

		fs << "Popping out elements...";
		while (!mystack.empty())
		{
			fs << ' ' << mystack.top();
			mystack.pop();
		}
		fs << '\n';
		clock.printStdTime();
	}
	fs << std::endl << std::endl;
	fs << "TEST POP" << std::endl << std::endl;
	{
		clock.setBeginStd();
		ft::stack<int> mystack;

		for (int i=0; i<5; ++i) mystack.push(i);

		fs << "Popping out elements...";
		while (!mystack.empty())
		{
			fs << ' ' << mystack.top();
			mystack.pop();
		}
		fs << '\n';
		clock.printStdTime();
	}
	fs << std::endl << std::endl;
	fs << "RELATIONAL OPERATORS" << std::endl << std::endl;
	{
		clock.setBeginStd();
		clock.printStdTime();
	}
	fs << std::endl << std::endl;
	fs.close();
	return 0;
}
