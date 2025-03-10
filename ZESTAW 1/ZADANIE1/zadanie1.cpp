#include <cassert>
#include <iostream>
#include <string>

using namespace std;

template <typename T> T maksimum(T a, T b) { return (a>b)?a:b;}


void test(){
    assert(maksimum(5,4) == 5);
    assert(maksimum<string>("abc","abcd") == "abcd");
    assert(maksimum<double>(3.14,5.8) == 5.8);

    std::cout << "Test zakonczyl sie sukcesem" << std::endl;
}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}
