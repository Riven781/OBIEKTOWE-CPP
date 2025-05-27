#include <iostream>
#include <concepts>

//g++ -std=c++20  zadanie1.cpp -o zad1

/*
Podaj przykłady wykorzystania konceptu std::integral tak aby szablon funkcji działał poprawnie tylko dla 
typów zmiennych spełniających wymagania tego konceptu (np. funkcja gcd – największy wspólny dzielnik). 

 

*/

template <typename T>
requires std::integral<T>  // ogranicza użycie tylko do typów całkowitych
auto gcd(T a, T b){
    if (b == 0) return a;
    else return gcd(b, a % b);
}


int main(int argc, char const *argv[])
{
    std::cout << gcd(20, 45) << std::endl;

    //std::cout << gcd(20., 45.) << std::endl;
    return 0;
}
