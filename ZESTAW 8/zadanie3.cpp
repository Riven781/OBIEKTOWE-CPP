#include <iostream>
#include <cmath>

/*
3. Funktor AddExpr jest używany przez szablon operatora dodawania dwóch funktorów:

template<typename LHS,typename RHS > AddExpr<LHS,RHS> operator+(const LHS &l, const RHS &r)

zwracany funktor może być podstawiony do funkcji całkującej. Dokonaj specjalizacji szablonu operatora dodawania dla przypadku,
w którym jeden z argumentów jest typu double tak aby możliwe było następujące użycie funkcji integrate:

integrate(x + 1.,0,1,0.001); 
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

// klasa funktor, która symbolizuje dodawanie
//jest to szablon wyrażenia dodawania
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

//operator dodawania, który z dwu składników utworzy obiekt typu AddExpr
template<typename LHS, typename RHS>
AddExpr<LHS, RHS> operator+(const LHS& l, const RHS& r){
    return AddExpr<LHS, RHS>(l, r);
};


//Żeby móc dodawać stałe potrzebujemy jeszcze specjalizacji szablonu dla przypadku, w którym jeden z argumentów jest typu double
template<typename LHS>
AddExpr<LHS, Constant> operator+(const LHS& l, double r){
    return AddExpr<LHS, Constant>(l, Constant(r));  //opkaowujemy w Constant, aby mozna było uzywać operatora nawiasów dla stałych 
};

template<typename RHS>
AddExpr<Constant, RHS> operator+(double l, const RHS& r){
    return AddExpr<Constant, RHS>(Constant(l), r);
};


int main(int argc, char const *argv[])
{
    Variable x;
    
    std::cout << integrate(x + 1.,0,1,0.001)  << std::endl;   //powinno byc 1.5


    return 0;
}