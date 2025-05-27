#include <iostream>
#include <concepts>

//g++ -std=c++20  zadanie5.cpp -o zad5

/*
    Pokaż przykład specjalizacji szablonu funkcji dla argumentu spełniającego wymaganie konceptu. 
*/

// Ogólny szablon klasy Vector dla dowolnego typu T
template <typename T>
class Vector{
public:
    Vector(){
        std::cout << "Vector<T>" << std::endl;
    }
};

// Specjalizacja szablonu klasy Vector tylko dla typów, które spełniają koncept std::regular
// kopiowalny, przenaszalny, porównywalny, domyślnie konstruowalny, zachowujący się jak podstawowe typy
template <std::regular Reg>
class Vector<Reg>{
public:
    Vector(){
        std::cout << "Vector<std::regular>" << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    Vector<int> vec1;
    Vector<int&> vec2;

    return 0;
}
