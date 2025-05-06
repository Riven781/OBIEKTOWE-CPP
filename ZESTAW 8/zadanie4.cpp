#include <iostream>
#include <cmath>

/*
4. Zaimplementuj szablony: operator/(double l, const RHS &r), DivExpr, sin oraz SinExpr. Dokonaj całowania następującej funkcji:

integrate(1./sin(x+ 1.,0,1,0.001); 
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

class Variable{
    public:
    double operator()(double x){
        return x;
    }
};

class Constant{
    double c;
public:
    Constant(double c) : c{c}{};
    double operator()(double x){
        return c;
    }
};

template<typename LHS, typename RHS>
class AddExpr{
public:
    AddExpr(const LHS& lhs,const  RHS& rhs) : lhs{lhs}, rhs{rhs}{};
    double operator()(double x){
        return lhs(x) + rhs(x);
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

// klasa funktor, która symbolizuje dzielenie
//jest to szablon wyrażenia dzielenia
template<typename LHS, typename RHS>
class DivExpr{
public:
    DivExpr(const LHS& lhs,const  RHS& rhs) : lhs{lhs}, rhs{rhs}{};
    double operator()(double x){
        return lhs(x) / rhs(x);
    }
private:
    LHS lhs;
    RHS rhs;
};

template<typename LHS, typename RHS>
DivExpr<LHS, RHS> operator/(const LHS& l, const RHS& r){
    return DivExpr<LHS, RHS>(l, r);
};

template<typename LHS>
DivExpr<LHS, Constant> operator/(const LHS& l, double r){
    return DivExpr<LHS, Constant>(l, Constant(r));
};

template<typename RHS>
DivExpr<Constant, RHS> operator/(double l, const RHS& r){
    return DivExpr<Constant, RHS>(Constant(l), r);
};

// klasa funktor, która symbolizuje operacje sin
// ARG - typ argumentu, który sam jest obiektem funkcyjnym
template<typename ARG>
class SinExpr{
public:
    SinExpr(const ARG & arg) : arg{arg}{};
    double operator()(double x){
        return std::sin(arg(x));
    }
private:
    ARG arg;
};

namespace my_fun
{
    //funkcja sin zwracająca obiekt funkcyjny
    template<typename ARG>
    SinExpr<ARG> sin(ARG arg ){
        return SinExpr<ARG>(arg);
    }


    // Przeciążona wersja funkcji sin dla stałej liczby
    SinExpr<Constant> sin(double arg ){
        return SinExpr<Constant>(Constant(arg));
    }
}



using namespace my_fun;



int main(int argc, char const *argv[])
{
    Variable x;
    
    std::cout << integrate(1./sin(x+ 1.),0,1,0.001)  << std::endl;   //powinno byc 1.0476

    std::cout << integrate(sin(x), 0,1,0.001)  << std::endl; //powinno być 0.4596

    std::cout << integrate(my_fun::sin(2.), 0,1,0.001)  << std::endl; //powinno być 0.90930


    return 0;
}