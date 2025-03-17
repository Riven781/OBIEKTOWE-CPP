#include <iostream>
#include <vector>

using namespace std;


template <class InputIterator, class T>
T accumulate(InputIterator first, InputIterator last, T init) {
T total=init;
 for( ; first != last;++first) {
  total+= *first;
 }
return total;
}


int main(int argc, char const *argv[])
{
    vector<int> v1{1,2,3,4,5};

    std::cout << accumulate(v1.begin(), v1.end(), 0) << std::endl;

    vector<double> v2{1.5, 2.5, 3.5};

    std::cout << accumulate(v2.begin(), v2.end(), 0.0) << std::endl;
    
    return 0;
}

