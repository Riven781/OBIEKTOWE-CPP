#include <iostream>
#include <memory>
#include <limits>

/*
2. Sprawdź czy wielkość inteligentnego wskaźnika różni się od wielkości zwykłego wskaźnika. 
*/

class LargeObject
{
private:
    int j;
    float x;
public:
    LargeObject(int j, float x) : j{j}, x{x}{};
    ~LargeObject(){};
    void doSomething(){};
};



int main(int argc, char const *argv[])
{
    std::unique_ptr<int> smart_int_ptr (new int{2} ); // Tworzenie inteligentnego wskaźnika na obiekt typu int
    int * int_ptr = new int{3};

    std::cout << "Rozmiar inteligentnego wskaznika: " << sizeof(smart_int_ptr) << " bajtow.\nRozmiar zwyklego wskaznika: " << sizeof(int_ptr) << " bajtow\n---" << std::endl;


    std::cout << "Rozmiar inteligentnego wskaznika: " << sizeof(std::unique_ptr<LargeObject> (new LargeObject{4,5.1} )) << " bajtow.\nRozmiar zwyklego wskaznika: " << sizeof(LargeObject *) << " bajtow\n---" << std::endl;

    std::shared_ptr<int> sharedPtr = std::make_shared<int>(30);

    std::cout << "Rozmiar std::shared_ptr: " << sizeof(sharedPtr) << " bajtw"  << std::endl;;
    /*
    
        std::cout << *smart_int_ptr << std::endl;
        std::cout << *int_ptr << std::endl;
    */

    return 0;
}
