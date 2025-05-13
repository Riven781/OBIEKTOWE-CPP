#include <iostream>
#include <memory>

struct B; // Deklaracja wstępna

struct A {
    std::shared_ptr<B> b_ptr;
    ~A() { std::cout << "A destroyed\n"; }
};

struct B {
    std::weak_ptr<A> a_ptr; // Słabe odniesienie
    ~B() { std::cout << "B destroyed\n"; }
};

int main() {
    auto a = std::make_shared<A>();
    auto b = std::make_shared<B>();

    a->b_ptr = b;
    b->a_ptr = a;

    // Po wyjściu z main obiekty A i B zostaną poprawnie zniszczone
}
