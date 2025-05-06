#include <iostream>
#include <cmath>

/*
1. Zaimplementuj szablon funkcji integrate, która jako pierwszy argument przyjmuje dowolny funktor. Funkcja integrate ma dokonywać całkowania w podanym zakresie np.:

std::cout<< ::integrate(sina(0),0,3.1415926,0.01)<<std::endl;

std::cout<< ::integrate(sina(1),0,3.1415926,0.01)<<std::endl;

std::cout<< ::integrate(sina(2),0,3.1415926,0.01)<<std::endl; 

*/

template<typename T>
double integrate(T f, double min, double max, double ds){   //przyjmuje dowolny funktor
    double integral{};
    for (double i = min; i < max; i+=ds)
    {
        integral += f(i);
    }
    return integral *ds;
    
}

struct sina{                       //funktor (obiekt funkcyjny) 
    sina(double a) : a{a}{};
    double operator()(double x){
        return sin(a * x);
    }
    private:
    double a;
};


int main(int argc, char const *argv[])
{
    std::cout << integrate(static_cast<double(*)(double)>(std::sin), 0.0, 1.2, 0.03) << std::endl;
    std::cout << integrate(sina(1), 0.0, 1.2, 0.03) << std::endl;
    std::cout << integrate(sina(2), 0.0, 1.2, 0.03) << std::endl;

    std::cout<< ::integrate(sina(1),0,3.1415926,0.01)<<std::endl; //powinno być 2

    std::cout<< ::integrate(sina(2),0,3.1415926,0.01)<<std::endl;   //powinno być 0
    return 0;
}
