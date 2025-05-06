#include <iostream>
#include <chrono>

template<int N> 
constexpr inline double pow(double x){
    return x * pow<N-1>(x);
}

template<>
constexpr inline double pow<0>(double x){
    return 1.0;
}

double pow_int(double x,int n) {
    double res = 1.0;
    for(int i = 0;i<n;++i)
        res*=x;
    return res;
};

template<int N>
void zmierz_czas(double x, int ile_powtorzen_wywolan){
    std::cout << "Dla funkcji szablonowej:" << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < ile_powtorzen_wywolan; i++)
    {
        pow<N>(x);
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto czas = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    std::cout << x << "^" << N << " w czasie: " << czas.count() << " nanoseconds" << std::endl;

    std::cout << "Dla zwyklej funkcji: " << std::endl;
    start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < ile_powtorzen_wywolan; i++)
    {
        pow_int(x, N);
    }
    stop = std::chrono::high_resolution_clock::now();
    czas = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    std::cout << x << "^" << N << " w czasie: " << czas.count() << " nanoseconds" << std::endl;
}

//g++ zadanie3.cpp -o zad3 -O1

int main(int argc, char const *argv[])
{
    std::cout << "TEST SZYBKOSCI:" << std::endl;


    zmierz_czas<22>(2232.3, 100000000);   //pow<2>(2.3);
    

    std::cout << "TEST POPRAWNOSCI WYLICZEN:" << std::endl;

    std::cout << "2.15^2 == " << pow<2>(2.15) << std::endl;
    std::cout << "5.15^4 == " << pow<4>(5.15) << std::endl;
    
    
    return 0;
}
