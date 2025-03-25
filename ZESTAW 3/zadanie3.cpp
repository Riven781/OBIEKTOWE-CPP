/*
W przeciwieństwie do szablonów funkcji, szablony klas nie mogą być 
przeciążane, a jedynie specjalizowane. Oznacza to, że w programie może 
istnieć tylko jeden szablon podstawowy o danej nazwie. Proszę 
zaimplementować specjalizację częściową, która jest dozwolona tylko dla 
szablonów klas, dla podanych podzbiorów parametrów:
    Stack<T,666>
    Stack<T*,N>
    Stack<double ,N>
    Stack<int *,N>
    Stack<double,666>
    Stack<double *,44>

*/


#include <iostream>

template <typename T, int N>
class Stack{
    public:
    Stack(){
        std::cout << "Utworzono Stack template <typename T, int N>" << std::endl;
    }
};

template <typename T>
class Stack<T,666>{
    public:
    Stack(){
        std::cout << "Utworzono Stack<T,666>" << std::endl;
    }
};


template <typename T, int N>
class Stack<T*,N>{
    public:
    Stack(){
        std::cout << "Utworzono Stack<T*,N>" << std::endl;
    }
};

template <int N>
class Stack<double,N>{
    public:
    Stack(){
        std::cout << "Utworzono Stack<double,N>" << std::endl;
    }
};

template <int N>
class Stack<int*,N>{
    public:
    Stack(){
        std::cout << "Utworzono Stack<int*,N>" << std::endl;
    }
};

template <>
class Stack<double,666>{
    public:
    Stack(){
        std::cout << "Utworzono Stack<double,666>" << std::endl;
    }
};

template <>
class Stack<double *,44>{
    public:
    Stack(){
        std::cout << "Utworzono Stack<double *,44>" << std::endl;
    }
};






int main(int argc, char const *argv[])
{
    Stack<int, 9> st1;
    Stack<int,666> st2;
    Stack<char*,5> st3;
    Stack<double, 90> st4;
    Stack<int*, 50> st5;
    Stack<double,666> st6;
    Stack<double *, 44> st7;
    return 0;
}
