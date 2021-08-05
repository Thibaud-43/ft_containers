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

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

int main(void)
{
	Time	clock;

	std::cout << "TEST CONSTRUCTORS" << std::endl << std::endl;
	{
		clock.setBeginStd();
		std::map<char,int> first;
		first['d']=5;

		first['a']=10;
		first['b']=30;
		first['c']=50;
		std::cout << "first contains:\n";
		std::map<char,int>::iterator it = first.begin();
		for (it=first.begin(); it!=first.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		std::map<char,int> second (first.begin(),first.end());

		std::map<char,int> third (second);

		std::map<char,int,classcomp> fourth;                 // class as Compare

		bool(*fn_pt)(char,char) = fncomp;
		std::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare

		clock.printStdTime();
	}
	{
		clock.setBeginFt();
		using namespace ft;
		map<char,int> first;
		first['d']=5;

		first['a']=10;
		first['b']=30;
		first['c']=50;

		std::cout << "first contains:\n";
		map<char,int>::iterator it = first.begin();
		for (it=first.begin(); it!=first.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		map<char,int> second (first.begin(),first.end());

		map<char,int> third (second);

		map<char,int,classcomp> fourth;                 // class as Compare

		bool(*fn_pt)(char,char) = fncomp;
		map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare

		clock.printFtTime();
	}
	std::cout << std::endl << std::endl;


	std::cout << "TEST ERASE" << std::endl << std::endl;
	{
		clock.setBeginStd();
		std::map<char,int> mymap;
		std::map<char,int>::iterator it;

		// insert some values:
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		mymap['d']=40;
		mymap['e']=50;
		mymap['f']=60;

		it=mymap.find('b');
		mymap.erase (it);                   // erasing by iterator

		mymap.erase ('c');                  // erasing by key

		it=mymap.find ('e');
		mymap.erase ( it, mymap.end() );    // erasing by range

		// show content:
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		clock.printStdTime();
	}
	{
		clock.setBeginFt();
		using namespace ft;
		map<char,int> mymap;
		map<char,int>::iterator it;

		// insert some values:
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		mymap['d']=40;
		mymap['e']=50;
		mymap['f']=60;

		it=mymap.find('b');
		mymap.erase (it);                   // erasing by iterator

		mymap.erase ('c');                  // erasing by key

		it=mymap.find ('e');
		mymap.erase ( it, mymap.end() );    // erasing by range

		// show content:
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		clock.printFtTime();
	}
	std::cout << std::endl << std::endl;



	std::cout << "TEST =" << std::endl << std::endl;
	{
		clock.setBeginStd();
		std::map<char,int> first;
		std::map<char,int> second;
		
		first['j']=12;
		first['x']=8;
		first['y']=16;
		first['z']=32;

		second=first;                // second now contains 3 ints
		first=std::map<char,int>();  // and first is now empty

		std::cout << "Size of first: " << first.size() << '\n';
		std::cout << "Size of second: " << second.size() << '\n';
		clock.printStdTime();
	}
	{
		clock.setBeginFt();
		using namespace ft;
		map<char,int> first;
		map<char,int> second;
		
		first['j']=12;
		first['x']=8;
		first['y']=16;
		first['z']=32;

		second=first;            // second now contains 3 ints
		first=map<char,int>();  // and first is now empty

		std::cout << "Size of first: " << first.size() << '\n';
		std::cout << "Size of second: " << second.size() << '\n';
		clock.printFtTime();
	}










	std::cout << std::endl << std::endl;
		std::cout << "TEST =" << std::endl << std::endl;
	{
		clock.setBeginStd();
		clock.printStdTime();
	}
	{
		clock.setBeginFt();
		using namespace ft;
		clock.printFtTime();
	}
	std::cout << std::endl << std::endl;
	std::cout << "TEST INSERT" << std::endl << std::endl;
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

		std::pair<std::map<char,int>::iterator,bool> ret;
		ret = mymap.insert ( std::pair<char,int>('z',500) );
		if (ret.second==false) {
			std::cout << "element 'z' already existed";
			std::cout << " with a value of " << ret.first->second << '\n';
		}
		// second insert function version (with hint position):
		std::map<char,int>::iterator it = mymap.begin();
		mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
		mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting

		// third insert function version (range insertion):
		std::map<char,int> anothermap;
		anothermap.insert(mymap.begin(),mymap.find('c'));

		// showing contents:
		std::cout << "mymap contains:\n";
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		std::cout << "anothermap contains:\n";
		for (it=anothermap.begin(); it!=anothermap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

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

		// second insert function version (with hint position):
		map<char,int>::iterator it = mymap.begin();
		mymap.insert (it, pair<char,int>('b',300));  // max efficiency inserting
		mymap.insert (it, pair<char,int>('c',400));  // no max efficiency inserting


		// third insert function version (range insertion):
		map<char,int> anothermap;
		anothermap.insert(mymap.begin(),mymap.find('c'));

		// showing contents:
		std::cout << "mymap contains:\n";
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		std::cout << "anothermap contains:\n";
		for (it=anothermap.begin(); it!=anothermap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		clock.printFtTime();
	}
	std::cout << std::endl << std::endl;
	return 0;
}
