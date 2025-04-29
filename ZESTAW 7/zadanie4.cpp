#include <iostream>
#include <cmath> 
#include <math.h>



template<int N>
constexpr double Silnia(){
    return N * Silnia<N - 1>();
}

template<>
constexpr double Silnia<0>(){
    return 1.0;
}

template<int N> 
constexpr inline double pow(double x){
    return x * pow<N-1>(x);
}

template<>
constexpr inline double pow<0>(double x){
    return 1.0;
}

template<int N>
constexpr double wartosc_n_wyrazu(double x){
    //std::cout << N << std::endl;
    return ((N % 2 == 0? 1. : -1.) * pow<2 * N + 1>(x)) / Silnia<2 * N +1>();
}

//N - wyrazow  rozwinięcia funkcji sin(x)
template<int N>
constexpr double sin(double x){
    return wartosc_n_wyrazu<N - 1>(x) + sin<N-1>(x);
};

template<>
constexpr double sin<0>(double x){
    return 0.0;
}

int main(int argc, char const *argv[])
{
    double x = 3.14;
  

    std::cout << sin<20>(3.14) << std::endl;  // 0.00159265
    std::cout << sin<20>(4.5) << std::endl;  // -0.977530
    std::cout << sin<20>(-1.) << std::endl;  //-0.84147098

    constexpr double s = sin<20>(2);    // <--- wyliczone w trkacie kompilacji
    std::cout << s << std::endl; //0.9092974
    return 0;
}
