#include <vector.hpp>
#include <ctime>
#include <deque>
#include <vector>
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


int main(void)
{
	Time	clock;

	std::ofstream fs;
  	fs.open ("results/ft_vector.txt");
	if (!fs.is_open())
    {    
        std::cout << "Error with file" << std::endl;
    }

	fs << "TEST CONSTRUCTORS" << std::endl << std::endl;
	{
		clock.setBeginFt();
		using namespace ft;
		// constructors used in the same order as described above:
		vector<int> first;                                	// empty vector of ints
		vector<int> second (4,100);       					// four ints with value 100
		vector<int> third (second.begin(),second.end());  // iterating through second
		vector<int> fourth (third);                       // a copy of third
		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {16,2,77,29};
		vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

		fs << "The contents of fifth are:";
		for (vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
			fs << ' ' << *it;
		fs << '\n';
		clock.printFtTime();
	}
	fs << std::endl << std::endl;

	fs << "TEST EGAL" << std::endl << std::endl;
	{
		clock.setBeginFt();
		using namespace ft;
		vector<int> foo (3,0);
		vector<int> bar (5,0);

		bar = foo;
		foo = vector<int>();

		fs << "Size of foo: " << int(foo.size()) << '\n';
		fs << "Size of bar: " << int(bar.size()) << '\n';

		clock.printFtTime();
	}
	fs << std::endl << std::endl;


	fs << "TEST BEGIN ET END" << std::endl << std::endl;
	{
		clock.setBeginFt();
		using namespace ft;
		vector<int> myvector;
		for (int i=1; i<=5; i++) myvector.push_back(i);

		fs << "myvector contains:";
		for (vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
			fs << ' ' << *it;
		fs << '\n';
		clock.printFtTime();
	}
	fs << std::endl << std::endl;

	fs << "TEST RBEGIN ET REND" << std::endl << std::endl;
	{
		clock.setBeginFt();
		using namespace ft;
		vector<int> myvector (5);  // 5 default-constructed ints

		int i=0;

		vector<int>::reverse_iterator rit = myvector.rbegin();
		vector<int>::reverse_iterator rit2 = myvector.rend();
		for (; rit!= rit2; ++rit)
			*rit = ++i;

		fs << "myvector contains:";
		for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
			fs << ' ' << *it;
		fs << '\n';
		clock.printFtTime();
	}
	fs << std::endl << std::endl;


	fs << "TEST SIZE" << std::endl << std::endl;
	{
		clock.setBeginFt();
		using namespace ft;
		vector<int> myints;
		fs << "0. size: " << myints.size() << '\n';

		for (int i=0; i<10; i++) myints.push_back(i);
		fs << "1. size: " << myints.size() << '\n';

		myints.insert (myints.end(),10,100);
		fs << "2. size: " << myints.size() << '\n';

		myints.pop_back();
		fs << "3. size: " << myints.size() << '\n';
		clock.printFtTime();
	}
	fs << std::endl << std::endl;


	fs << "TEST MAX SIZE" << std::endl << std::endl;

	{
		clock.setBeginFt();
		using namespace ft;
		vector<int> myvector;

		// set some content in the vector:
		for (int i=0; i<100; i++) myvector.push_back(i);

		fs << "size: " << myvector.size() << "\n";
		fs << "capacity: " << myvector.capacity() << "\n";
		fs << "max_size: " << myvector.max_size() << "\n";
		clock.printFtTime();
	}
	fs << std::endl << std::endl;

	fs << "TEST RESIZE" << std::endl << std::endl;

	{
		clock.setBeginFt();
		using namespace ft;
		vector<int> myvector;

		// set some initial content:
		for (int i=1;i<10;i++) myvector.push_back(i);

		myvector.resize(5);
		myvector.resize(8,100);
		myvector.resize(12);

		fs << "myvector contains:";
		for (size_t i=0;i<myvector.size();i++)
			fs << ' ' << myvector[i];
		fs << '\n';
		clock.printFtTime();
	}
	fs << std::endl << std::endl;

	fs << "TEST CAPACITY" << std::endl << std::endl;

	{
		clock.setBeginFt();
		using namespace ft;
		vector<int> myvector;

		// set some content in the vector:
		for (int i=0; i<100; i++) myvector.push_back(i);

		fs << "size: " << (int) myvector.size() << '\n';
		fs << "capacity: " << (int) myvector.capacity() << '\n';
		fs << "max_size: " << (int) myvector.max_size() << '\n';

		clock.printFtTime();
	}
	fs << std::endl << std::endl;

	fs << "TEST EMPTY" << std::endl << std::endl;

	{
		clock.setBeginFt();
		using namespace ft;
		vector<int> myvector;
		int sum (0);

		for (int i=1;i<=10;i++) myvector.push_back(i);

		while (!myvector.empty())
		{
			sum += myvector.back();
			myvector.pop_back();
		}

		fs << "total: " << sum << '\n';
		clock.printFtTime();
	}
	fs << std::endl << std::endl;


	fs << "TEST RESERVE" << std::endl << std::endl;
	{
		clock.setBeginFt();
		using namespace ft;
		vector<int>::size_type sz;

		vector<int> foo;
		sz = foo.capacity();
		fs << "making foo grow:\n";
		for (int i=0; i<100; ++i) {
			foo.push_back(i);
			if (sz!=foo.capacity()) {
			sz = foo.capacity();
			fs << "capacity changed: " << sz << '\n';
			}
		}

		vector<int> bar;
		sz = bar.capacity();
		bar.reserve(100);   // this is the only difference with foo above
		fs << "making bar grow:\n";
		for (int i=0; i<100; ++i) {
			bar.push_back(i);
			if (sz!=bar.capacity()) {
			sz = bar.capacity();
			fs << "capacity changed: " << sz << '\n';
			}
		}
		clock.printFtTime();
	}
	fs << std::endl << std::endl;
	fs << "TEST []" << std::endl << std::endl;
	{
		clock.setBeginFt();
		using namespace ft;
		vector<int> myvector (10);   // 10 zero-initialized elements

		vector<int>::size_type sz = myvector.size();

		// assign some values:
		for (unsigned i=0; i<sz; i++) myvector[i]=i;

		// reverse vector using operator[]:
		for (unsigned i=0; i<sz/2; i++)
		{
			int temp;
			temp = myvector[sz-1-i];
			myvector[sz-1-i]=myvector[i];
			myvector[i]=temp;
		}

		fs << "myvector contains:";
		for (unsigned i=0; i<sz; i++)
			fs << ' ' << myvector[i];
		fs << '\n';

		clock.printFtTime();
	}
	fs << std::endl << std::endl;

	fs << "TEST AT" << std::endl << std::endl;
	{
		clock.setBeginFt();
		using namespace ft;
		vector<int> myvector (10);   // 10 zero-initialized ints

		// assign some values:
		for (unsigned i=0; i<myvector.size(); i++)
			myvector.at(i)=i;

		fs << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			fs << ' ' << myvector.at(i);
		fs << '\n';
		clock.printFtTime();
	}
	fs << std::endl << std::endl;
	fs << "TEST FRONT" << std::endl << std::endl;
	{
		clock.setBeginFt();
		using namespace ft;
		vector<int> myvector;

		myvector.push_back(78);
		myvector.push_back(16);

		// now front equals 78, and back 16

		myvector.front() -= myvector.back();

		fs << "myvector.front() is now " << myvector.front() << '\n';

		clock.printFtTime();
	}
	fs << std::endl << std::endl;
	fs << "TEST BACK" << std::endl << std::endl;
	{
		clock.setBeginFt();
		using namespace ft;
		vector<int> myvector;

		myvector.push_back(10);

		while (myvector.back() != 0)
		{
			myvector.push_back ( myvector.back() -1 );
		}

		fs << "myvector contains:";
		for (unsigned i=0; i<myvector.size() ; i++)
			fs << ' ' << myvector[i];
		fs << '\n';

		clock.printFtTime();
	}
	fs << std::endl << std::endl;
	fs << "TEST ASSIGN" << std::endl << std::endl;
	{
		clock.setBeginFt();
		using namespace ft;
		vector<int> first;
		vector<int> second;
		vector<int> third;

		first.assign (7,100);             // 7 ints with a value of 100

		vector<int>::iterator it;
		it=first.begin()+1;

		second.assign (it,first.end()-1); // the 5 central values of first


		int myints[] = {1776,7,4};
		third.assign (myints,myints+3);   // assigning from array.

		fs << "Size of first: " << int (first.size()) << '\n';
		fs << "Size of second: " << int (second.size()) << '\n';
		fs << "Size of third: " << int (third.size()) << '\n';

		fs << "Capacity of first: " << int (first.capacity()) << '\n';
		fs << "Capacity of second: " << int (second.capacity()) << '\n';
		fs << "Capacity of third: " << int (third.capacity()) << '\n';
		clock.printFtTime();
	}
	fs << std::endl << std::endl;
	fs << "TEST PUSH BACK" << std::endl << std::endl;
	{
		clock.setBeginFt();
		using namespace ft;
		vector<int> myvector;
		int myint = 10;

		fs << "Please enter some integers (enter 0 to end):\n";

		do {
			myvector.push_back (myint--);
		} while (myint);

		fs << "myvector stores " << int(myvector.size()) << " numbers.\n";
		clock.printFtTime();
	}
	fs << std::endl << std::endl;
	fs << "TEST POP BACK" << std::endl << std::endl;
	{
		clock.setBeginFt();
		using namespace ft;
		vector<int> myvector;
		int sum (0);
		myvector.push_back (100);
		myvector.push_back (200);
		myvector.push_back (300);

		while (!myvector.empty())
		{
			sum+=myvector.back();
			myvector.pop_back();
		}

		fs << "The elements of myvector add up to " << sum << '\n';

		clock.printFtTime();
	}
	fs << std::endl << std::endl;
	fs << "TEST INSERT" << std::endl << std::endl;
	{
		clock.setBeginFt();
		using namespace ft;
		vector<int> myvector (3,100);
		vector<int>::iterator it;

		it = myvector.begin();
		it = myvector.insert (it , 200);
		myvector.insert (it, 2,300);

		// "it" no longer valid, get a new one:
		it = myvector.begin();

		vector<int> anothervector (2,400);
		myvector.insert (it+2,anothervector.begin(),anothervector.end());

		int myarray [] = { 501,502,503 };
		myvector.insert (myvector.begin(), myarray, myarray+3);

		fs << "myvector contains:";
		for (it=myvector.begin(); it < myvector.end(); it++)
			fs << ' ' << *it;
		fs << '\n';

		clock.printFtTime();
	}
	fs << std::endl << std::endl;
	fs << "TEST ERASE" << std::endl << std::endl;
	{
		clock.setBeginFt();
		using namespace ft;
		vector<int> myvector;

		// set some values (from 1 to 10)
		for (int i=1; i<=10; i++) myvector.push_back(i);

		// erase the 6th element
		myvector.erase (myvector.begin()+5);

		// erase the first 3 elements:
		myvector.erase (myvector.begin(),myvector.begin()+3);

		fs << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); ++i)
			fs << ' ' << myvector[i];
		fs << '\n';
		clock.printFtTime();
	}
	fs << std::endl << std::endl;
	fs << "TEST SWAP" << std::endl << std::endl;
	{
		clock.setBeginFt();
		using namespace ft;
		vector<int> foo (3,100);   // three ints with a value of 100
		vector<int> bar (5,200);   // five ints with a value of 200
		
		foo.swap(bar);

		fs << "foo contains:";
		for (unsigned i=0; i<foo.size(); i++)
			fs << ' ' << foo[i];
		fs << '\n';

		fs << "bar contains:";
		for (unsigned i=0; i<bar.size(); i++)
			fs << ' ' << bar[i];
		fs << '\n';
		clock.printFtTime();
	}
	fs << std::endl << std::endl;
	fs << "TEST CLEAR" << std::endl << std::endl;
	{
		clock.setBeginFt();
		using namespace ft;
		vector<int> myvector;
		myvector.push_back (100);
		myvector.push_back (200);
		myvector.push_back (300);

		fs << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			fs << ' ' << myvector[i];
		fs << '\n';

		myvector.clear();
		myvector.push_back (1101);
		myvector.push_back (2202);

		fs << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			fs << ' ' << myvector[i];
		fs << '\n';
		clock.printFtTime();
	}
	fs << std::endl << std::endl;
	fs << "TEST GET ALLOCATOR" << std::endl << std::endl;

	{
		clock.setBeginFt();
		using namespace ft;
		vector<int> myvector;
		int * p;
		unsigned int i;

		// allocate an array with space for 5 elements using vector's allocator:
		p = myvector.get_allocator().allocate(5);

		// construct values in-place on the array:
		for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

		fs << "The allocated array contains:";
		for (i=0; i<5; i++) fs << ' ' << p[i];
			fs << '\n';

		// destroy and deallocate:
		for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
			myvector.get_allocator().deallocate(p,5);	
		clock.printFtTime();
	}
	fs << std::endl << std::endl;
	fs << "TEST RELATIONAL OPERATORS" << std::endl << std::endl;

	{
		clock.setBeginFt();
		using namespace ft;
		vector<int> foo (3,100);   // three ints with a value of 100
		vector<int> bar (2,200);   // two ints with a value of 200

		if (foo==bar) fs << "foo and bar are equal\n";
		if (foo!=bar) fs << "foo and bar are not equal\n";
		if (foo< bar) fs << "foo is less than bar\n";
		if (foo> bar) fs << "foo is greater than bar\n";
		if (foo<=bar) fs << "foo is less than or equal to bar\n";
		if (foo>=bar) fs << "foo is greater than or equal to bar\n";

		clock.printFtTime();
	}
	fs << std::endl << std::endl;
	fs << "TEST SWAP" << std::endl << std::endl;
	{
		clock.setBeginFt();
		using namespace ft;
		vector<int> foo (3,100);   // three ints with a value of 100
		vector<int> bar (5,200);   // five ints with a value of 200

		foo.swap(bar);

		fs << "foo contains:";
		for (vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
			fs << ' ' << *it;
		fs << '\n';

		fs << "bar contains:";
		for (vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
			fs << ' ' << *it;
		fs << '\n';

		clock.printFtTime();
	}
	fs << std::endl << std::endl;
		fs << "OTHER TEST" << std::endl << std::endl;
	{
		clock.setBeginFt();
		using namespace ft;
		vector<int>		vec;
		vector<int>::iterator	it = vec.begin();
		const vector<int>::iterator	it2 = vec.end();
		fs << (it2 == it) << std::endl;
		clock.printFtTime();
	}
	fs << std::endl << std::endl;
	fs << "NICO TEST" << std::endl << std::endl;
	{
		clock.setBeginFt();
		ft::vector<ft::vector<int> > v;
		ft::vector<int > v2(static_cast<size_t>(100), 42);
		ft::vector<int > v3(static_cast<size_t>(100), 42);
		//ft::vector<int > v4(static_cast<size_t>(100), 42);
		//ft::vector<int > v5(static_cast<size_t>(100), 42);
		v.push_back(v2);
		v.push_back(v3);
		std::cout <<"capacity: " << v.capacity() << std::endl;
		//v.push_back(v4);
		//v.push_back(v5);
		clock.printFtTime();
	}
	fs << std::endl << std::endl;
	fs << "NICO TEST2" << std::endl << std::endl;
	{
		clock.setBeginFt();
		std::deque<int> q1;
		q1.push_back(10);
		q1.push_back(11);
		q1.push_back(12);
		q1.push_back(13);
		std::deque<int>::reverse_iterator it = q1.rbegin();
		std::deque<int>::reverse_iterator end = q1.rend();
		ft::vector<int> v(it, end);
		for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
			fs << *it << ", ";
		fs << std::endl;
		ft::vector<int>::iterator itv = v.begin();
		v.insert(itv + 1, it, end - 1);
		for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
			fs << *it << ", ";
		fs << std::endl;
		clock.printFtTime();
	}
	fs << std::endl << std::endl;
	fs.close();
	return 0;
}
