#include <iostream>
#include <vector>
#include "vector.hpp"

int main ()
{
  	// {
		// std::cout<< "test myvector" << std::endl;
		// ft::vector<int> myvector;
		// myvector.push_back(1);
		// myvector.push_back(2);
		// myvector.push_back(3);
		// ft::vector<int>::iterator it;
		// std::cout << "myvector before contains:";
		// for (it=myvector.begin(); it<myvector.end(); it++)
		// 	std::cout << ' ' << *it;
		// std::cout << '\n';
		// it = myvector.begin()+1;
		// ft::vector<int>::iterator newIt = myvector.insert(it,300);
		// myvector.insert (myvector.begin() + 2, 3, 400);
		// std::cout << "myvector after contains:";
		// myvector.erase(myvector.begin());
		// myvector.erase(myvector.begin(), myvector.begin() + 2);
		// for (it=myvector.begin(); it<myvector.end(); it++)
		// 	std::cout << ' ' << *it;
	// 	// std::cout << '\n';
	// 	std::vector<int> myvector;

	// 	for (int i=1; i<=10; i++) myvector.push_back(i);

	// 	// erase the 6th element
	// 	// myvector.erase (myvector.begin()+5);

	// 	// erase the first 3 elements:
	// 	// myvector.erase (myvector.begin(),myvector.begin()+3);

	// 	std::cout << "stdvector contains:";
	// 	for (unsigned i=0; i<myvector.size(); ++i)
	// 		std::cout << ' ' << myvector[i];
	// 	std::cout << '\n';
	// }
   {
		ft::vector<int> myvector;

		for (int i=1; i<=10; i++)
		{
			myvector.push_back(i);
			// std::cout<< myvector[i-1]<<std::endl;
		}

		ft::vector<int>::iterator it = myvector.begin();
		while(it !=myvector.end())
		{
			std::cout<< *it << std::endl;
			it++;
		}

		// erase the 6th element
		// myvector.erase (myvector.begin()+5);

		// erase the first 3 elements:
		// myvector.erase (myvector.begin(),myvector.begin()+3);

		// std::cout << "my_vector contains:";
		// for (size_t i=0; i<myvector.size(); i++)
		// 	std::cout << ' ' << myvector[i];
		// std::cout << '\n';
	}
  return 0;
}