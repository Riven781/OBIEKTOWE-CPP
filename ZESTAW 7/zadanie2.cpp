#include <iostream>

template<int N, int M>
struct Pow
{
    static constexpr int val = N * Pow<N, M - 1>::val;
};

template<int N>
struct Pow<N, 0>
{
    static constexpr int val = 1;
};


int main(int argc, char const *argv[])
{
    std::cout << "3^0 == " << Pow<3,0>::val << std::endl;
    std::cout << "3^1 == " << Pow<3,1>::val << std::endl;
    std::cout << "3^2 == " << Pow<3,2>::val << std::endl;

    std::cout << "2^5 == " << Pow<2,5>::val << std::endl;
    std::cout << "13^2 == " << Pow<13,2>::val << std::endl;

    std::cout << "0^3 == " << Pow<0,3>::val << std::endl;
    
    return 0;
}

