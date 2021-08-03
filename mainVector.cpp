#include <vector.hpp>
#include <vector>
#include <ctime>
#include <testClass.hpp>

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
		using namespace std;
		// constructors used in the same order as described above:
		vector<int> first;                                // empty vector of ints
		vector<int> second (4,100);                       // four ints with value 100
		vector<int> third (second.begin(),second.end());  // iterating through second
		vector<int> fourth (third);                       // a copy of third
		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {16,2,77,29};
		vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

		cout << "The contents of fifth are:";
		for (vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
			cout << ' ' << *it;
		cout << '\n';
		clock.printStdTime();
	}
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

		std::cout << "The contents of fifth are:";
		for (vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
		clock.printFtTime();
	}
	std::cout << std::endl << std::endl;

	std::cout << "TEST EGAL" << std::endl << std::endl;
	{
		clock.setBeginStd();
		using namespace std;
		vector<int> foo (3,0);
		vector<int> bar (5,0);

		bar = foo;
		foo = vector<int>();

		cout << "Size of foo: " << int(foo.size()) << '\n';
		cout << "Size of bar: " << int(bar.size()) << '\n';
		clock.printStdTime();

	}
	{
		clock.setBeginFt();
		using namespace ft;
		vector<int> foo (3,0);
		vector<int> bar (5,0);

		bar = foo;
		foo = vector<int>();

		std::cout << "Size of foo: " << int(foo.size()) << '\n';
		std::cout << "Size of bar: " << int(bar.size()) << '\n';

		clock.printFtTime();
	}
	std::cout << std::endl << std::endl;


	std::cout << "TEST BEGIN ET END" << std::endl << std::endl;
	{
		clock.setBeginStd();
		using namespace std;
		vector<int> myvector;
		for (int i=1; i<=5; i++) myvector.push_back(i);

		cout << "myvector contains:";
		for (vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
			cout << ' ' << *it;
		cout << '\n';
		clock.printStdTime();

	}
	{
		clock.setBeginFt();
		using namespace ft;
		vector<int> myvector;
		for (int i=1; i<=5; i++) myvector.push_back(i);

		std::cout << "myvector contains:";
		for (vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
		clock.printFtTime();
	}
	std::cout << std::endl << std::endl;

	std::cout << "TEST RBEGIN ET REND" << std::endl << std::endl;
	{
		clock.setBeginStd();

		std::vector<int> myvector (5);  // 5 default-constructed ints

		int i=0;

		std::vector<int>::reverse_iterator rit = myvector.rbegin();
		for (; rit!= myvector.rend(); ++rit)
			*rit = ++i;

		std::cout << "myvector contains:";
		for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
		clock.printStdTime();

	}
	{
		clock.setBeginFt();
		using namespace ft;
		vector<int> myvector (5);  // 5 default-constructed ints

		int i=0;

		vector<int>::reverse_iterator rit = myvector.rbegin();
		vector<int>::reverse_iterator rit2 = myvector.rend();
		for (; rit!= rit2; ++rit)
			*rit = ++i;

		std::cout << "myvector contains:";
		for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
		clock.printFtTime();
	}
	std::cout << std::endl << std::endl;


	std::cout << "TEST SIZE" << std::endl << std::endl;
	{
		clock.setBeginStd();

		std::vector<int> myints;
		std::cout << "0. size: " << myints.size() << '\n';

		for (int i=0; i<10; i++) myints.push_back(i);
		std::cout << "1. size: " << myints.size() << '\n';

		myints.insert (myints.end(),10,100);
		std::cout << "2. size: " << myints.size() << '\n';

		myints.pop_back();
		std::cout << "3. size: " << myints.size() << '\n';
		clock.printStdTime();

	}
	{
		clock.setBeginFt();
		using namespace ft;
		vector<int> myints;
		std::cout << "0. size: " << myints.size() << '\n';

		for (int i=0; i<10; i++) myints.push_back(i);
		std::cout << "1. size: " << myints.size() << '\n';

		myints.insert (myints.end(),10,100);
		std::cout << "2. size: " << myints.size() << '\n';

		myints.pop_back();
		std::cout << "3. size: " << myints.size() << '\n';
		clock.printFtTime();
	}
	std::cout << std::endl << std::endl;


	std::cout << "TEST MAX SIZE" << std::endl << std::endl;
	{
		clock.setBeginStd();

		std::vector<int> myvector;

		// set some content in the vector:
		for (int i=0; i<100; i++) myvector.push_back(i);

		std::cout << "size: " << myvector.size() << "\n";
		std::cout << "capacity: " << myvector.capacity() << "\n";
		std::cout << "max_size: " << myvector.max_size() << "\n";
		clock.printStdTime();

	}

	{
		clock.setBeginFt();
		using namespace ft;
		vector<int> myvector;

		// set some content in the vector:
		for (int i=0; i<100; i++) myvector.push_back(i);

		std::cout << "size: " << myvector.size() << "\n";
		std::cout << "capacity: " << myvector.capacity() << "\n";
		std::cout << "max_size: " << myvector.max_size() << "\n";
		clock.printFtTime();
	}
	std::cout << std::endl << std::endl;

	std::cout << "TEST RESIZE" << std::endl << std::endl;
	{
		clock.setBeginStd();

		std::vector<int> myvector;

		// set some initial content:
		for (int i=1;i<10;i++) myvector.push_back(i);

		myvector.resize(5);
		myvector.resize(8,100);
		myvector.resize(12);

		std::cout << "myvector contains:";
		for (size_t i=0;i<myvector.size();i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
		clock.printStdTime();

	}

	{
		clock.setBeginFt();
		using namespace ft;
		vector<int> myvector;

		// set some initial content:
		for (int i=1;i<10;i++) myvector.push_back(i);

		myvector.resize(5);
		myvector.resize(8,100);
		myvector.resize(12);

		std::cout << "myvector contains:";
		for (size_t i=0;i<myvector.size();i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
		clock.printFtTime();
	}
	std::cout << std::endl << std::endl;

	std::cout << "TEST CAPACITY" << std::endl << std::endl;
	{
		clock.setBeginStd();

		std::vector<int> myvector;

		// set some content in the vector:
		for (int i=0; i<100; i++) myvector.push_back(i);

		std::cout << "size: " << (int) myvector.size() << '\n';
		std::cout << "capacity: " << (int) myvector.capacity() << '\n';
		std::cout << "max_size: " << (int) myvector.max_size() << '\n';
		clock.printStdTime();

	}

	{
		clock.setBeginFt();
		using namespace ft;
		vector<int> myvector;

		// set some content in the vector:
		for (int i=0; i<100; i++) myvector.push_back(i);

		std::cout << "size: " << (int) myvector.size() << '\n';
		std::cout << "capacity: " << (int) myvector.capacity() << '\n';
		std::cout << "max_size: " << (int) myvector.max_size() << '\n';

		clock.printFtTime();
	}
	std::cout << std::endl << std::endl;

	std::cout << "TEST EMPTY" << std::endl << std::endl;
	{
		clock.setBeginStd();

		std::vector<int> myvector;
		int sum (0);

		for (int i=1;i<=10;i++) myvector.push_back(i);

		while (!myvector.empty())
		{
			sum += myvector.back();
			myvector.pop_back();
		}

		std::cout << "total: " << sum << '\n';
		clock.printStdTime();

	}

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

		std::cout << "total: " << sum << '\n';
		clock.printFtTime();
	}
	std::cout << std::endl << std::endl;


	std::cout << "TEST RESERVE" << std::endl << std::endl;
	{
		clock.setBeginStd();

		std::vector<int>::size_type sz;

		std::vector<int> foo;
		sz = foo.capacity();
		std::cout << "making foo grow:\n";
		for (int i=0; i<100; ++i) {
			foo.push_back(i);
			if (sz!=foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
			}
		}

		std::vector<int> bar;
		sz = bar.capacity();
		bar.reserve(100);   // this is the only difference with foo above
		std::cout << "making bar grow:\n";
		for (int i=0; i<100; ++i) {
			bar.push_back(i);
			if (sz!=bar.capacity()) {
			sz = bar.capacity();
			std::cout << "capacity changed: " << sz << '\n';
			}
		}
		clock.printStdTime();

	}
	{
		clock.setBeginFt();
		using namespace ft;
		vector<int>::size_type sz;

		vector<int> foo;
		sz = foo.capacity();
		std::cout << "making foo grow:\n";
		for (int i=0; i<100; ++i) {
			foo.push_back(i);
			if (sz!=foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
			}
		}

		vector<int> bar;
		sz = bar.capacity();
		bar.reserve(100);   // this is the only difference with foo above
		std::cout << "making bar grow:\n";
		for (int i=0; i<100; ++i) {
			bar.push_back(i);
			if (sz!=bar.capacity()) {
			sz = bar.capacity();
			std::cout << "capacity changed: " << sz << '\n';
			}
		}
		clock.printFtTime();
	}
	std::cout << std::endl << std::endl;


	std::cout << "TEST []" << std::endl << std::endl;
	{
		clock.setBeginStd();

		std::vector<int> myvector (10);   // 10 zero-initialized elements

		std::vector<int>::size_type sz = myvector.size();

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

		std::cout << "myvector contains:";
		for (unsigned i=0; i<sz; i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
		clock.printStdTime();

	}
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

		std::cout << "myvector contains:";
		for (unsigned i=0; i<sz; i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';

		clock.printFtTime();
	}
	std::cout << std::endl << std::endl;

	std::cout << "TEST AT" << std::endl << std::endl;
	{
		clock.setBeginStd();

		std::vector<int> myvector (10);   // 10 zero-initialized ints

		// assign some values:
		for (unsigned i=0; i<myvector.size(); i++)
			myvector.at(i)=i;

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector.at(i);
		std::cout << '\n';
		clock.printStdTime();

	}

	{
		clock.setBeginFt();
		using namespace ft;
		vector<int> myvector (10);   // 10 zero-initialized ints

		// assign some values:
		for (unsigned i=0; i<myvector.size(); i++)
			myvector.at(i)=i;

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector.at(i);
		std::cout << '\n';
		clock.printFtTime();
	}
	std::cout << std::endl << std::endl;
	std::cout << "TEST FRONT" << std::endl << std::endl;
	{
		clock.setBeginStd();

		std::vector<int> myvector;

		myvector.push_back(78);
		myvector.push_back(16);

		// now front equals 78, and back 16

		myvector.front() -= myvector.back();

		std::cout << "myvector.front() is now " << myvector.front() << '\n';

		clock.printStdTime();
	}

	{
		clock.setBeginFt();
		using namespace ft;
		vector<int> myvector;

		myvector.push_back(78);
		myvector.push_back(16);

		// now front equals 78, and back 16

		myvector.front() -= myvector.back();

		std::cout << "myvector.front() is now " << myvector.front() << '\n';

		clock.printFtTime();
	}
	std::cout << std::endl << std::endl;

	std::cout << "TEST BACK" << std::endl << std::endl;
	{
		clock.setBeginStd();

		std::vector<int> myvector;

		myvector.push_back(10);

		while (myvector.back() != 0)
		{
			myvector.push_back ( myvector.back() -1 );
		}

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size() ; i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';

		clock.printStdTime();
	}
	{
		clock.setBeginFt();
		using namespace ft;
		vector<int> myvector;

		myvector.push_back(10);

		while (myvector.back() != 0)
		{
			myvector.push_back ( myvector.back() -1 );
		}

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size() ; i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';

		clock.printFtTime();
	}
	std::cout << std::endl << std::endl;




	std::cout << "TEST ASSIGN" << std::endl << std::endl;
	{
		clock.setBeginStd();

		using namespace std;
		vector<int> first;
		vector<int> second;
		vector<int> third;

		first.assign (7,100);             // 7 ints with a value of 100

		vector<int>::iterator it;
		it=first.begin()+1;

		second.assign (it,first.end()-1); // the 5 central values of first

		int myints[] = {1776,7,4};
		third.assign (myints,myints+3);   // assigning from array.

		cout << "Size of first: " << int (first.size()) << '\n';
		cout << "Size of second: " << int (second.size()) << '\n';
		cout << "Size of third: " << int (third.size()) << '\n';

		cout << "Capacity of first: " << int (first.capacity()) << '\n';
		cout << "Capacity of second: " << int (second.capacity()) << '\n';
		cout << "Capacity of third: " << int (third.capacity()) << '\n';
		clock.printStdTime();
	}
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

		std::cout << "Size of first: " << int (first.size()) << '\n';
		std::cout << "Size of second: " << int (second.size()) << '\n';
		std::cout << "Size of third: " << int (third.size()) << '\n';

		std::cout << "Capacity of first: " << int (first.capacity()) << '\n';
		std::cout << "Capacity of second: " << int (second.capacity()) << '\n';
		std::cout << "Capacity of third: " << int (third.capacity()) << '\n';
		clock.printFtTime();
	}
	std::cout << std::endl << std::endl;


	std::cout << "TEST PUSH BACK" << std::endl << std::endl;
	{
		clock.setBeginStd();

		std::vector<int> myvector;
		int myint;

		std::cout << "Please enter some integers (enter 0 to end):\n";

		do {
			std::cin >> myint;
			myvector.push_back (myint);
		} while (myint);

		std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
		clock.printStdTime();
	}
	{
		clock.setBeginFt();
		using namespace ft;
		vector<int> myvector;
		int myint;

		std::cout << "Please enter some integers (enter 0 to end):\n";

		do {
			std::cin >> myint;
			myvector.push_back (myint);
		} while (myint);

		std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
		clock.printFtTime();
	}
	std::cout << std::endl << std::endl;





	std::cout << "TEST POP BACK" << std::endl << std::endl;
	{
		clock.setBeginStd();

		std::vector<int> myvector;
		int sum (0);
		myvector.push_back (100);
		myvector.push_back (200);
		myvector.push_back (300);

		while (!myvector.empty())
		{
			sum+=myvector.back();
			myvector.pop_back();
		}

		std::cout << "The elements of myvector add up to " << sum << '\n';

		clock.printStdTime();
	}
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

		std::cout << "The elements of myvector add up to " << sum << '\n';

		clock.printFtTime();
	}
	std::cout << std::endl << std::endl;

	std::cout << "TEST INSERT" << std::endl << std::endl;
	{
		clock.setBeginStd();

		std::vector<int> myvector (3,100);
		std::vector<int>::iterator it;

		it = myvector.begin();
		it = myvector.insert ( it , 200 );

		myvector.insert (it,2,300);

		// "it" no longer valid, get a new one:
		it = myvector.begin();

		std::vector<int> anothervector (2,400);
		myvector.insert (it+2,anothervector.begin(),anothervector.end());

		int myarray [] = { 501,502,503 };
		myvector.insert (myvector.begin(), myarray, myarray+3);

		std::cout << "myvector contains:";
		for (it=myvector.begin(); it<myvector.end(); it++)
			std::cout << ' ' << *it;
		std::cout << '\n';
		clock.printStdTime();
	}
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

		std::cout << "myvector contains:";
		for (it=myvector.begin(); it < myvector.end(); it++)
			std::cout << ' ' << *it;
		std::cout << '\n';

		clock.printFtTime();
	}
	std::cout << std::endl << std::endl;

	std::cout << "TEST ERASE" << std::endl << std::endl;
	{
		clock.setBeginStd();
		std::vector<int> myvector;

		// set some values (from 1 to 10)
		for (int i=1; i<=10; i++) myvector.push_back(i);

		// erase the 6th element
		myvector.erase (myvector.begin()+5);

		// erase the first 3 elements:
		myvector.erase (myvector.begin(),myvector.begin()+3);

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); ++i)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
		clock.printStdTime();
		
	}

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

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); ++i)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
		clock.printFtTime();
	}
	std::cout << std::endl << std::endl;

	std::cout << "TEST SWAP" << std::endl << std::endl;
	{
		clock.setBeginStd();
		std::vector<int> foo (3,100);   // three ints with a value of 100
		std::vector<int> bar (5,200);   // five ints with a value of 200

		foo.swap(bar);

		std::cout << "foo contains:";
		for (unsigned i=0; i<foo.size(); i++)
			std::cout << ' ' << foo[i];
		std::cout << '\n';

		std::cout << "bar contains:";
		for (unsigned i=0; i<bar.size(); i++)
			std::cout << ' ' << bar[i];
		std::cout << '\n';
		clock.printStdTime();
	}

	{
		clock.setBeginFt();
		using namespace ft;
		vector<int> foo (3,100);   // three ints with a value of 100
		vector<int> bar (5,200);   // five ints with a value of 200

		foo.swap(bar);

		std::cout << "foo contains:";
		for (unsigned i=0; i<foo.size(); i++)
			std::cout << ' ' << foo[i];
		std::cout << '\n';

		std::cout << "bar contains:";
		for (unsigned i=0; i<bar.size(); i++)
			std::cout << ' ' << bar[i];
		std::cout << '\n';
		clock.printFtTime();
	}
	std::cout << std::endl << std::endl;

	std::cout << "TEST CLEAR" << std::endl << std::endl;
	{
		clock.setBeginStd();
		std::vector<int> myvector;
		myvector.push_back (100);
		myvector.push_back (200);
		myvector.push_back (300);

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';

		myvector.clear();
		myvector.push_back (1101);
		myvector.push_back (2202);

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';	
		clock.printStdTime();
	}

	{
		clock.setBeginFt();
		using namespace ft;
		vector<int> myvector;
		myvector.push_back (100);
		myvector.push_back (200);
		myvector.push_back (300);

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';

		myvector.clear();
		myvector.push_back (1101);
		myvector.push_back (2202);

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
		clock.printFtTime();
	}
	std::cout << std::endl << std::endl;
	std::cout << "TEST GET ALLOCATOR" << std::endl << std::endl;
	{
		clock.setBeginStd();
		std::vector<int> myvector;
		int * p;
		unsigned int i;

		// allocate an array with space for 5 elements using vector's allocator:
		p = myvector.get_allocator().allocate(5);

		// construct values in-place on the array:
			for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

		std::cout << "The allocated array contains:";
		for (i=0; i<5; i++) std::cout << ' ' << p[i];
			std::cout << '\n';

		// destroy and deallocate:
		for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
		myvector.get_allocator().deallocate(p,5);		
		clock.printStdTime();
	}

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

		std::cout << "The allocated array contains:";
		for (i=0; i<5; i++) std::cout << ' ' << p[i];
			std::cout << '\n';

		// destroy and deallocate:
		for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
			myvector.get_allocator().deallocate(p,5);	
		clock.printFtTime();
	}
	std::cout << std::endl << std::endl;
	std::cout << "TEST RELATIONAL OPERATORS" << std::endl << std::endl;
	{
		clock.setBeginStd();
		std::vector<int> foo (3,100);   // three ints with a value of 100
		std::vector<int> bar (2,200);   // two ints with a value of 200

		if (foo==bar) std::cout << "foo and bar are equal\n";
		if (foo!=bar) std::cout << "foo and bar are not equal\n";
		if (foo< bar) std::cout << "foo is less than bar\n";
		if (foo> bar) std::cout << "foo is greater than bar\n";
		if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

		clock.printStdTime();
	}

	{
		clock.setBeginFt();
		using namespace ft;
		vector<int> foo (3,100);   // three ints with a value of 100
		vector<int> bar (2,200);   // two ints with a value of 200

		if (foo==bar) std::cout << "foo and bar are equal\n";
		if (foo!=bar) std::cout << "foo and bar are not equal\n";
		if (foo< bar) std::cout << "foo is less than bar\n";
		if (foo> bar) std::cout << "foo is greater than bar\n";
		if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

		clock.printFtTime();
	}
	std::cout << std::endl << std::endl;
	std::cout << "TEST SWAP" << std::endl << std::endl;
	{
		clock.setBeginStd();
		std::vector<int> foo (3,100);   // three ints with a value of 100
		std::vector<int> bar (5,200);   // five ints with a value of 200

		foo.swap(bar);

		std::cout << "foo contains:";
		for (std::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		std::cout << "bar contains:";
		for (std::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
				
		clock.printStdTime();
	}

	{
		clock.setBeginFt();
		using namespace ft;
		vector<int> foo (3,100);   // three ints with a value of 100
		vector<int> bar (5,200);   // five ints with a value of 200

		foo.swap(bar);

		std::cout << "foo contains:";
		for (vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		std::cout << "bar contains:";
		for (vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		clock.printFtTime();
	}
	std::cout << std::endl << std::endl;
	return 0;
}
