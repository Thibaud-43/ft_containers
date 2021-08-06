#include <map.hpp>
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

	void	setBeginFt(void)
	{
		m_begin_std = clock();
	}
	void	setBeginStd(void)
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
	std::ofstream fs;
  	fs.open ("results/ft_map.txt");
	if (!fs.is_open())
    {    
        std::cout << "Error with file" << std::endl;
    }
	fs << "TEST CONSTRUCTORS" << std::endl << std::endl;
	{
		clock.setBeginFt();
		ft::map<char,int> first;
		first['d']=5;

		first['a']=10;
		first['b']=30;
		first['c']=50;
		fs << "first contains:\n";
		ft::map<char,int>::iterator it = first.begin();
		for (it=first.begin(); it!=first.end(); ++it)
			fs << it->first << " => " << it->second << '\n';
		ft::map<char,int> second (first.begin(),first.end());

		ft::map<char,int> third (second);

		ft::map<char,int,classcomp> fourth;                 // class as Compare

		bool(*fn_pt)(char,char) = fncomp;
		ft::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare

		clock.printStdTime();
	}
	fs << std::endl << std::endl;

	fs << "TEST =" << std::endl << std::endl;
	{
		clock.setBeginFt();
		ft::map<char,int> first;
		ft::map<char,int> second;
		
		first['j']=12;
		first['x']=8;
		first['y']=16;
		first['z']=32;

		second=first;                // second now contains 3 ints
		first=ft::map<char,int>();  // and first is now empty

		fs << "Size of first: " << first.size() << '\n';
		fs << "Size of second: " << second.size() << '\n';
		clock.printFtTime();
	}
	fs << std::endl << std::endl;

	fs << "TEST BEGIN END" << std::endl << std::endl;
	{
		clock.setBeginFt();
		ft::map<char,int> mymap;

		mymap['b'] = 100;
		mymap['a'] = 200;
		mymap['c'] = 300;

		// show content:
		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			fs << it->first << " => " << it->second << '\n';
		clock.printStdTime();
	}
	fs << std::endl << std::endl;

	fs << "TEST RBEGIN REND" << std::endl << std::endl;
	{
		clock.setBeginFt();
		ft::map<char,int> mymap;

		mymap['x'] = 100;
		mymap['y'] = 200;
		mymap['z'] = 300;

		// show content:
		ft::map<char,int>::reverse_iterator rit;
		for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
			fs << rit->first << " => " << rit->second << '\n';

		clock.printStdTime();
	}
	fs << std::endl << std::endl;
	fs << "TEST EMPTY" << std::endl << std::endl;
	{
		clock.setBeginFt();
		ft::map<char,int> mymap;

		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;

		while (!mymap.empty())
		{
		fs << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
		mymap.erase(mymap.begin());
		}
		clock.printStdTime();
	}

	fs << std::endl << std::endl;
		fs << "TEST SIZE" << std::endl << std::endl;
	{
		clock.setBeginFt();
		ft::map<char,int> mymap;
		mymap['a']=101;
		mymap['b']=202;
		mymap['c']=302;

		fs << "mymap.size() is " << mymap.size() << '\n';

		clock.printStdTime();
	}
	fs << std::endl << std::endl;
	fs << "TEST MAXSIZE" << std::endl << std::endl;
	{
		clock.setBeginFt();
		int i;
		ft::map<int,int> mymap;

		if (mymap.max_size()>1000)
		{
			for (i=0; i<1000; i++) mymap[i]=0;
				fs << "The map contains 1000 elements.\n";
		}
		else fs << "The map could not hold 1000 elements.\n";

		clock.printStdTime();
	}
	fs << std::endl << std::endl;
	fs << "TEST []" << std::endl << std::endl;
	{
		clock.setBeginFt();
		ft::map<char,std::string> mymap;

		mymap['a']="an element";
		mymap['b']="another element";
		mymap['c']=mymap['b'];

		fs << "mymap['a'] is " << mymap['a'] << '\n';
		fs << "mymap['b'] is " << mymap['b'] << '\n';
		fs << "mymap['c'] is " << mymap['c'] << '\n';
		fs << "mymap['d'] is " << mymap['d'] << '\n';

		fs << "mymap now contains " << mymap.size() << " elements.\n";

		clock.printStdTime();
	}
	fs << std::endl << std::endl;
	fs << "TEST INSERT" << std::endl << std::endl;
	{
		clock.setBeginFt();
		 ft::map<char,int> mymap;

		// first insert function version (single parameter):
		mymap.insert ( ft::pair<char,int>('a',100) );
		mymap.insert ( ft::pair<char,int>('z',200) );

		ft::pair<ft::map<char,int>::iterator,bool> ret;
		ret = mymap.insert ( ft::pair<char,int>('z',500) );
		if (ret.second==false) {
			fs << "element 'z' already existed";
			fs << " with a value of " << ret.first->second << '\n';
		}

		// second insert function version (with hint position):
		ft::map<char,int>::iterator it = mymap.begin();
		mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
		mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting

		// third insert function version (range insertion):
		ft::map<char,int> anothermap;
		anothermap.insert(mymap.begin(),mymap.find('c'));

		// showing contents:
		fs << "mymap contains:\n";
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			fs << it->first << " => " << it->second << '\n';

		fs << "anothermap contains:\n";
		for (it=anothermap.begin(); it!=anothermap.end(); ++it)
			fs << it->first << " => " << it->second << '\n';
		clock.printStdTime();
	}
	fs << std::endl << std::endl;
	fs << "TEST ERASE" << std::endl << std::endl;
	{
		clock.setBeginFt();
		ft::map<char,int> mymap;
		ft::map<char,int>::iterator it;

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
			fs << it->first << " => " << it->second << '\n';

		clock.printStdTime();
	}
	fs << std::endl << std::endl;
		fs << "TEST SWAP" << std::endl << std::endl;
	{
		clock.setBeginFt();
		ft::map<char,int> foo,bar;

		foo['x']=100;
		foo['y']=200;

		bar['a']=11;
		bar['b']=22;
		bar['c']=33;

		foo.swap(bar);

		fs << "foo contains:\n";
		for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
			fs << it->first << " => " << it->second << '\n';

		fs << "bar contains:\n";
		for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
			fs << it->first << " => " << it->second << '\n';

		clock.printStdTime();
	}
	fs << std::endl << std::endl;
		fs << "TEST CLEAR" << std::endl << std::endl;
	{
		clock.setBeginFt();
		ft::map<char,int> mymap;

		mymap['x']=100;
		mymap['y']=200;
		mymap['z']=300;

		fs << "mymap contains:\n";
		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			fs << it->first << " => " << it->second << '\n';

		mymap.clear();
		mymap['a']=1101;
		mymap['b']=2202;

		fs << "mymap contains:\n";
		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			fs << it->first << " => " << it->second << '\n';
		clock.printStdTime();
	}
	fs << std::endl << std::endl;
		fs << "TEST KEY COMPARE" << std::endl << std::endl;
	{
		clock.setBeginFt();
		ft::map<char,int> mymap;

		ft::map<char,int>::key_compare mycomp = mymap.key_comp();

		mymap['a']=100;
		mymap['b']=200;
		mymap['c']=300;

		fs << "mymap contains:\n";

		char highest = mymap.rbegin()->first;     // key value of last element

		ft::map<char,int>::iterator it = mymap.begin();
		do {
			fs << it->first << " => " << it->second << '\n';
		} while ( mycomp((*it++).first, highest) );

		fs << '\n';

		clock.printStdTime();
	}
	fs << std::endl << std::endl;
		fs << "TEST FIND" << std::endl << std::endl;
	{
		clock.setBeginFt();
		ft::map<char,int> mymap;
		ft::map<char,int>::iterator it;

		mymap['a']=50;
		mymap['b']=100;
		mymap['c']=150;
		mymap['d']=200;

		it = mymap.find('b');
		if (it != mymap.end())
		mymap.erase (it);

		// print content:
		fs << "elements in mymap:" << '\n';
		fs << "a => " << mymap.find('a')->second << '\n';
		fs << "c => " << mymap.find('c')->second << '\n';
		fs << "d => " << mymap.find('d')->second << '\n';

		clock.printStdTime();
	}
	fs << std::endl << std::endl;
		fs << "TEST COUNT" << std::endl << std::endl;
	{
		clock.setBeginFt();
		ft::map<char,int> mymap;
		char c;

		mymap ['a']=101;
		mymap ['c']=202;
		mymap ['f']=303;

		for (c='a'; c<'h'; c++)
		{
			fs << c;
			if (mymap.count(c)>0)
				fs << " is an element of mymap.\n";
			else 
				fs << " is not an element of mymap.\n";
		}

		clock.printStdTime();
	}
	fs << std::endl << std::endl;
			fs << "TEST UPPER/LOWER BOND" << std::endl << std::endl;
	{
		clock.setBeginFt();
		ft::map<char,int> mymap;
		ft::map<char,int>::iterator itlow,itup;

		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;

		itlow=mymap.lower_bound ('b');  // itlow points to b
		itup=mymap.upper_bound ('d');   // itup points to e (not d!)

		mymap.erase(itlow,itup);        // erases [itlow,itup)

		// print content:
		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			fs << it->first << " => " << it->second << '\n';

		clock.printStdTime();
	}

	fs << std::endl << std::endl;
			fs << "TEST EQUAL RANGE" << std::endl << std::endl;
	{
		clock.setBeginFt();
		  ft::map<char,int> mymap;

		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;

		ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
		ret = mymap.equal_range('b');

		fs << "lower bound points to: ";
		fs << ret.first->first << " => " << ret.first->second << '\n';

		fs << "upper bound points to: ";
		fs << ret.second->first << " => " << ret.second->second << '\n';

		clock.printStdTime();
	}
	fs << std::endl << std::endl;
			fs << "TEST GET ALLOCATOR" << std::endl << std::endl;
	{
		clock.setBeginFt();
		  int psize;
		ft::map<char,int> mymap;
		ft::pair<const char,int>* p;

		// allocate an array of 5 elements using mymap's allocator:
		p=mymap.get_allocator().allocate(5);

		// assign some values to array
		psize = sizeof(ft::map<char,int>::value_type)*5;

		fs << "The allocated array has a size of " << psize << " bytes.\n";

		mymap.get_allocator().deallocate(p,5);

		clock.printStdTime();
	}
	fs << std::endl << std::endl;

	fs.close();
	return 0;
}
