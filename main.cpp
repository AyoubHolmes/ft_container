#include <vector>
#include "vector.hpp"
#include <iostream>

using namespace std;

class Test {
    public:
        Test() {
            std::cout << "Hello Test" << std::endl;
        };
};

/* int main() {
    std::allocator<int> test;
    int *arr = test.allocate(3);
    test.construct(arr, 100);
    std::cout << arr[0] << std::endl;
    std::cout << arr[1] << std::endl;
    std::cout << arr[2] << std::endl;
    test.deallocate(arr, 3);
    std::cout << "*************** Simple Test ***************" << std::endl;
    std::allocator<Test> tst2;
    Test *t = tst2.allocate(1);
    Test *t2 = new Test();
    delete t2;
    tst2.deallocate(t, 1);
}
 */
int main()
{
    // Declaring a vector
   /*  vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
  
    // Declaring an iterator
    vector<float> k; */
    ft::vector<int> firstVector(3, 1336);
    ft::vector<int> secondVector(firstVector);
    ft::vector<int>::reverse_iterator it( firstVector.rbegin());
    int i = 0;
    for (; it != firstVector.rend(); it++)
    {
        std::cout << *it << std::endl;
    }
    
    

    return 0;
}