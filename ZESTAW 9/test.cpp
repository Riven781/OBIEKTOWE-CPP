#include <iostream>
#include <memory>
#include <limits>

class LargeObject
{
private:
    int j;
    float x;
public:
    LargeObject(int j, float x) : j{j}, x{x}{};
    ~LargeObject(){};
    void doSomething(){
        std::cout << "I'm doing..." << std::endl;
    };
};




int main(int argc, char const *argv[])
{
    std::unique_ptr<int> smart_int_ptr (new int{2} );
    int * int_ptr = new int{3};

    auto ptrA = std::make_unique<LargeObject>(6,5.9);

    ptrA->doSomething();

    auto ptrB = std::move(ptrA);

    ptrB->doSomething();

    ptrA->doSomething();

    std::cout << "/* message */" << std::endl;

    std::cout << "ptrA: " << ptrA.get() << std::endl;

    ptrA->doSomething();  //NIEZDEFINIOWANE ZACHOWANIE

    if (ptrA)
    ptrA->doSomething();
    else
        std::cout << "ptrA is nullptr" << std::endl;


    return 0;
}
