#include <iostream>
#include <memory>

//g++ cykliczna_zaleznosc.cpp -o cz

struct B; // Deklaracja wstępna

struct A {
    std::shared_ptr<B> b_ptr;
    ~A() { std::cout << "A destroyed\n"; }
};

struct B {
    std::shared_ptr<A> a_ptr;
    ~B() { std::cout << "B destroyed\n"; }
};

int main() {
    auto a = std::make_shared<A>();
    auto b = std::make_shared<B>();

    a->b_ptr = b;
    b->a_ptr = a;

    // Obiekty A i B nigdy nie zostaną zniszczone - cykliczna zależność
}
