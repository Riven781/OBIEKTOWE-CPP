#include <iostream>
#include <vector>
using namespace std;


template <typename T>
class has_value_type{
    typedef char one;
    typedef struct{char c[2];} two;

    template<typename U>
    static one test(typename U::value_type*);
    template<typename U>
    static two test(...);

public:
    enum {
        yes = (sizeof(test<T>(nullptr)) == sizeof(one)) 
    };
};


int main(int argc, char const *argv[])
{
    std::cout << ::has_value_type<int>::yes << std::endl;
    std::cout << ::has_value_type<vector<int>>::yes << std::endl;
    return 0;
}
