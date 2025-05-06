#include <iostream>
#include <cmath>

/*
5. Operatory arytmetyczne nie będą miały jak automatycznie wydedukować typu T : template<typename T,typename LHS,typename RHS > Add<T,LHS,RHS> 
operator+(const LHS &l, const RHS &r)

ponieważ, typ T nie pojawia się w argumentach wywołania. Zaimplementuj dodatkową klasę Expr "opakowującej" wyrażenia,
 która będzie przenosiła informację o typie. Przedstaw przykłady całkowania funkcji z użyciem zmiennej innego typu niż double. 
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

template <typename T>
class Variable{
    public:
    T operator()(T x){
        return x;
    }
};

template <typename T>
class Constant{
    T c;
public:
    Constant(T c) : c{c}{};
    T operator()(T x){
        return c;
    }
};

template<typename T,typename LHS, typename RHS>
class AddExpr{
public:
    AddExpr(const LHS& lhs,const  RHS& rhs) : lhs{lhs}, rhs{rhs}{};
    T operator()(T x){
        return lhs(x) + rhs(x);
    }
private:
    LHS lhs;
    RHS rhs;
};

// klasa Expr "opakowująca" wyrażenia, przenosi informację o typie
template<typename T, typename R = Variable<T>>
class Expr{
    R _rep;
public:
    Expr() {};
    Expr(R rep) : _rep{rep}{};
    T operator()(T x){
        return _rep(x);
    }
    R rep() const{
        return _rep;
    };

};


template<typename T, typename LHS, typename RHS>
Expr<T, AddExpr<T, LHS, RHS>> operator+(const Expr<T,LHS>& l, const Expr<T,RHS>& r){      //T pojawia się w argumentach wywołania, jest możliwa jego dedukcja
    return Expr<T, AddExpr<T, LHS, RHS>>(AddExpr<T,LHS, RHS>(l.rep(), r.rep()));
};


template<typename T, typename LHS>
Expr<T, AddExpr<T, LHS, Constant<T>>> operator+(const Expr<T,LHS>& l, const T r){    
    return Expr<T, AddExpr<T, LHS, Constant<T>>>(AddExpr<T,LHS, Constant<T>>(l.rep(), Constant<T>(r)));
};

//po wywolaniu f(i)
//Expr ----> AddExpr  ---->  lhs(x) + rhs(x)  (mogą być to już funktory zwracające wartość (np Variable lub Constant) lub kolejne zagnieżdzenia (np. Expr itd))

template<typename T, typename RHS>
Expr<T, AddExpr<T, Constant<T>, RHS>> operator+(const T l, const Expr<T,RHS>& r){      
    return Expr<T, AddExpr<T, Constant<T>, RHS>>(AddExpr<T,Constant<T>, RHS>(Constant<T>(l), r.rep()));
};






int main(int argc, char const *argv[])
{
  


    Expr<float> y;

    std::cout << integrate(y,0,1,0.001)  << std::endl;   

    std::cout << integrate(y + 1.f,0,1,0.001)  << std::endl;   



    Expr<double> x;

    std::cout << integrate(x,0,1,0.001)  << std::endl;   //powinno byc 0.5

    std::cout << integrate(x + 1.,0,1,0.001)  << std::endl;   //powinno byc 1.5



    return 0;
}