#include <iostream>

template<template<int N> class C, int K> void f(C<K>){
    /*
    parametr C określa szablon klasy 
    posiadający jeden parametr typu int. Parametr N służy tylko 
    do definicji szablonu C i nie może być użyty nigdzie indziej
    */
    std::cout << K << std::endl;
}

template<int N> struct SomeClass {};

int main(int argc, char const *argv[])
{
    SomeClass<1> c1;
    SomeClass<2> c2;

    f(c1); //C = SomeClass, K= 1
    f(c2);

    

    return 0;
}
