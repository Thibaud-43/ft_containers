#include <vector.hpp>
#include <vector>
#include <testClass.hpp>



int main(void)
{

	std::cout << "TEST CONSTRUCTORS" << std::endl << std::endl;
	{
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
	}
	{
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
	}
	std::cout << std::endl << std::endl;

	std::cout << "TEST EGAL" << std::endl << std::endl;
	{
		using namespace std;
		vector<int> foo (3,0);
		vector<int> bar (5,0);

		bar = foo;
		foo = vector<int>();

		cout << "Size of foo: " << int(foo.size()) << '\n';
		cout << "Size of bar: " << int(bar.size()) << '\n';
	}
	{
		using namespace ft;
		vector<int> foo (3,0);
		vector<int> bar (5,0);

		bar = foo;
		foo = vector<int>();

		std::cout << "Size of foo: " << int(foo.size()) << '\n';
		std::cout << "Size of bar: " << int(bar.size()) << '\n';

	}
	std::cout << std::endl << std::endl;


	std::cout << "TEST BEGIN ET END" << std::endl << std::endl;
	{
		using namespace std;
		vector<int> myvector;
		for (int i=1; i<=5; i++) myvector.push_back(i);

		cout << "myvector contains:";
		for (vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
			cout << ' ' << *it;
		cout << '\n';
	}
	{
		using namespace ft;
		vector<int> myvector;
		for (int i=1; i<=5; i++) myvector.push_back(i);

		std::cout << "myvector contains:";
		for (vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	std::cout << std::endl << std::endl;

	std::cout << "TEST ASSIGN" << std::endl << std::endl;
	{
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
	}
	{
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
	}
	std::cout << std::endl << std::endl;


	std::cout << "TEST PUSH BACK" << std::endl << std::endl;
	{
		std::vector<int> myvector;
		int myint;

		std::cout << "Please enter some integers (enter 0 to end):\n";

		do {
			std::cin >> myint;
			myvector.push_back (myint);
		} while (myint);

		std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
	}
	{
		using namespace ft;
		vector<int> myvector;
		int myint;

		std::cout << "Please enter some integers (enter 0 to end):\n";

		do {
			std::cin >> myint;
			myvector.push_back (myint);
		} while (myint);

		std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
	}
	std::cout << std::endl << std::endl;



	std::cout << "TEST []" << std::endl << std::endl;
	{
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
	}
	{
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

	}
	std::cout << std::endl << std::endl;

	std::cout << "TEST BACK" << std::endl << std::endl;
	{
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

	}
	{
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

	}
	std::cout << std::endl << std::endl;

	std::cout << "TEST POP BACK" << std::endl << std::endl;
	{
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

	}
	{
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

	}
	std::cout << std::endl << std::endl;
	return 0;
}
