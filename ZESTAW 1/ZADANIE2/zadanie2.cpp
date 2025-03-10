#include <iostream>
#include <cassert>

using namespace std;

template <typename T, typename U> T convert(U u){
    return T(u);
}


void test(){
    assert(convert<int>(5.45) == 5);
    std::cout << "5.45 -> " << convert<int>(5.45)  << std::endl;
    assert(convert<int>('a') == 97);
    std::cout << "a -> " << convert<int>('a')  << std::endl;
    assert(convert<char>(98) == 'b');
    std::cout << "98 -> " << convert<char>(98)  << std::endl;

    std::cout << "Test zakonczyl sie sukcesem" << std::endl;
    
}


int main(int argc, char const *argv[])
{
    test();
    return 0;
}
