#include <iostream>
#include <concepts>

//g++ -std=c++20  zadanie4.cpp -o zad4


/*
    Pokaż przykład przeładowania szablonu funkcji przy wykorzystaniu konceptów. 
*/



// Funkcja szablonowa display dla typów całkowitych 
template<std::integral T>
void display(T val){
    std::cout << "integral value: " << val << std::endl;
}

// Przeciążona wersja funkcji display – dla typów zmiennoprzecinkowych (funkcja zostanie wygenerowana tylko dla typów zmiennoprzecinkowych)
template<std::floating_point T>
void display(T val){
    std::cout << "floating value: " << val << std::endl;
}



int main(int argc, char const *argv[])
{
    display(10);
    display(34.34);
    return 0;
}
