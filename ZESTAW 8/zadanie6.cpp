#include <iostream>
#include <cmath>

/*
6. Zaimplementuj rozszerzenie klasy Variable dla przypadku funktorów dwóch zmiennych, tj. klasy First oraz Second. 
Podaj przykład całkowania prostej funkcji np. x + y. 
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


//funkcja calkująca po 2 zmiennych
template<typename T>
double integrate2D(T f, double xmin, double xmax, double ymin, double ymax, double ds) {
    double integral{};
    for (double x = xmin; x < xmax; x += ds) {
        for (double y = ymin; y < ymax; y += ds) {
            integral += f(x, y);
        }
    }
    return integral * ds * ds;
}


//reprezentuje pierwszy argument i może występować w funktorach jedno- lub dwuargumentowych
class First{
public:
    double operator()(double x){
        return x;
    }
    double operator()(double x, double){
        return x;
    }
};

//reprezentuje drugi argument funktora, więc może występować tylko jako funkcja dwuargumentowa
class Second{
public:
    double operator()(double, double y){
        return y;
    }
};



class Constant{
    double c;
public:
    Constant(double c) : c{c}{};
    double operator()(double){
        return c;
    }
    double operator()(double, double){
        return c;
    }

};

// Klasa reprezentująca wyrażenie dodawania dwóch funktorów (np. x + y)
template<typename LHS, typename RHS>
class AddExpr{
public:
    AddExpr(const LHS& lhs,const  RHS& rhs) : lhs{lhs}, rhs{rhs}{};
    double operator()(double x){
        return lhs(x) + rhs(x);
    }
    double operator()(double x, double y){       //dodanie dwuargumentowego operatora nawiasów
        return lhs(x, y) + rhs(x, y);
    }
private:
    LHS lhs;
    RHS rhs;
};


template<typename LHS, typename RHS>
AddExpr<LHS, RHS> operator+(const LHS& l, const RHS& r){
    return AddExpr<LHS, RHS>(l, r);
};

template<typename LHS>
AddExpr<LHS, Constant> operator+(const LHS& l, double r){
    return AddExpr<LHS, Constant>(l, Constant(r));
};

template<typename RHS>
AddExpr<Constant, RHS> operator+(double l, const RHS& r){
    return AddExpr<Constant, RHS>(Constant(l), r);
};









int main(int argc, char const *argv[])
{
    First x;

    Second y;
    
    std::cout << integrate2D(x + y, 0, 1, 0, 1, 0.001) << std::endl; // powinno być 1.0

    std::cout << integrate(x, 0,1,0.001)  << std::endl; //powinno być 0.5

    std::cout << integrate2D(x + y + 1., 0, 1, 0, 1, 0.001) << std::endl; // powinno być 2

  


    return 0;
}