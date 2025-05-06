#include <iostream>
#include <cmath>

/*
2. Stwórz odpowiednie funktory Variable oraz Constant, które mogą być używane jako argumenty funkcji integrate: 
Variable x;

integrate(x,0,1,0.001);

integrate(Constant(1.0),0,1,0.001); 
*/

template<typename T>
double integrate(T f, double min, double max, double ds){
    double integral{};
    for (double i = min; i < max; i+=ds)
    {
        integral += f(i);
    }
    return integral *ds;
    
}


//zmienna to funktor który zwraca własny argument: 
class Variable{
    public:
    double operator()(double x){
        return x;
    }
};


// Stała to funktor, który zwraca wartość niezależną od swojego argumentu: 
class Constant{
    double c;
public:
    Constant(double c) : c{c}{};
    double operator()(double x){
        return c;
    }
};



int main(int argc, char const *argv[])
{
    Variable x;
    
    std::cout << integrate(x,0,1,0.001)  << std::endl;   //powinno byc 0.5

    std::cout << integrate(Constant(1.0),0,1,0.001)  << std::endl;  //powinno byc 1

    Constant c(2.0);

    std::cout << integrate(c, 0,1,0.001)  << std::endl;  //powinno byc 2

    
    

   
    return 0;
}
