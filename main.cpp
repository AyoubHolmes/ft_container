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
    vector<int> v;
    vector<int> v2;


    
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    v2.push_back(1 * 2);
    v2.push_back(2 * 2);
    v2.push_back(3 * 2);
    v2.push_back(4 * 2);

    /* ft::vector<int>::iterator it1 = v.begin();
    ft::vector<int>::iterator it2 = v.end(); */

    vector<int>::iterator itv1 = v2.begin();
    vector<int>::iterator itv2 = v2.end();
    vector<int>::iterator it1 = v.begin();
    vector<int>::iterator it2 = v.end();
    

    vector<int>::iterator test = v.insert(itv1 + 1, 5);
    std::cout << *test << std::endl;
    for (; itv1 != itv2 ; itv1++)
    {
        std::cout << *itv1 << std::endl;
    }
    // for (; it1 != it2 ; it1++)
    // {
    //     std::cout << *it1 << std::endl;
    // }

    /* v.pop_back();
    v.pop_back();
    it2 = v.end();
    std::cout << std::endl; */

    /* v2.assign(5, 10);

    itv1 = v2.begin();
    itv2 = v2.end();

    for (; itv1 != itv2 ; itv1++)
    {
        std::cout << *itv1 << std::endl;
    } */
    /* for (; itv1 != itv2 ; itv1++)
    {
        std::cout << *itv1 << std::endl;
    }
    std::cout << std::endl;
    v2.assign(it1, it2);
    itv1 = v2.begin();
    for (; itv1 != itv2 ; itv1++)
    {
        std::cout << *itv1 << std::endl;
    } */

    // Declaring an iterator

    /* ft::vector<int> firstVector(3, 1336);
    ft::vector<int> secondVector(firstVector);
    ft::vector<int>::reverse_iterator it( firstVector.rbegin());
    int i = 0;
    for (; it != firstVector.rend(); it++)
    {
        std::cout << *it << std::endl;
    } */

    return 0;
}