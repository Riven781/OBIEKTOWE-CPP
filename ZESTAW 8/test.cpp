#include <iostream>
#include "test.h" // zakładamy, że tak się nazywa twój plik

int main() {
   
    
   
    

    Expr<double> x;

    std::cout << integrate(x,0,1,0.001)  << std::endl;   //powinno byc 0.5

    std::cout << integrate(x + 1.,0,1,0.001)  << std::endl;   //powinno byc 1.5


    Expr<int> y;

    std::cout << integrate(y,0,1,0.001)  << std::endl;   //powinno byc 0.5

    std::cout << integrate(y + 1,0,1,0.001)  << std::endl;   //powinno byc 1.5

    return 0;
}