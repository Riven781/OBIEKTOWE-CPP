#include <iostream>
#include <concepts>

//g++ -std=c++20  zadanie3.cpp -o zad3

/*
    Zaimplementuj prostą klasę MyVector z metodą push_back, której argumenty musza spełniać koncept std::copyable<T>. 
    Stwórz klasę z usuniętym konstruktorem kopiującym i spróbuj wykorzystać obiekt tej klasy dla pokazania błędu kompilacji. 

*/

template <typename T>
class MyVector{
public:
    void push_back(const T&) requires std::copyable<T>{  // 'requires std::copyable<T>' oznacza, że ta funkcja będzie dostępna tylko dla typów, które można kopiować (czyli mają dostępny konstruktor kopiujący)

    }
};

// typ, który nie jest kopiowalny
class NotCopyable{
    NotCopyable() = default;
    NotCopyable(const NotCopyable&) = delete;
};

int main(int argc, char const *argv[])
{
    MyVector<int> vec1;
    vec1.push_back(2020);

    MyVector<NotCopyable> vec2;
    //vec2.push_back(NotCopyable());



    return 0;
}