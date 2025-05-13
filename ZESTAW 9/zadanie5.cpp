#include <iostream>
#include <memory>

/*
5. Pokaż, że używanie wskaźnika typu shared_ptr zapewnia wywołanie destruktora w przypadku znikania ostatniego z nich.
*/

class LargeObject
{
private:
    int j;
    float x;
public:
    LargeObject(int j, float x) : j{j}, x{x}{
        std::cout << "Konstruktor wywolany" << std::endl;
    };
    ~LargeObject(){
        std::cout << "Destruktor wywolany" << std::endl;
    };
    void doSomething(){};
};





int main(int argc, char const *argv[])
{

    auto s1 = std::make_shared<LargeObject>(5, 8.0);  

    std::cout << "Licznik referencji: " << s1.use_count() << std::endl; //licznik ref = 1

    std::shared_ptr<LargeObject> s2;  //to tylko pusty wskaznik

    std::cout << "Licznik referencji: " << s1.use_count() << std::endl;

    {
        s2 = s1;   //licznik ref = 2
        std::cout << "Licznik referencji: " << s1.use_count() << std::endl; 

        auto s3(s2);    //licznik ref = 3

        std::cout << "Licznik referencji: " << s1.use_count() << std::endl;
    }//licznik ref = 2

    std::cout << "Licznik referencji: " << s1.use_count() << std::endl; 

    s2.reset(); // To samo co ptr = nullptr;

    //licznik ref = 1

    std::cout << "Licznik referencji: " << s1.use_count() << std::endl; 


    /*
    
    s1.reset();

    std::cout << "Licznik referencji: " << s1.use_count() << std::endl; 
    
    */

    //auto s1 = std::make_shared<int>(5);

    return 0;
}//licznik ref = 0
