#include <iostream>


template<int N> 
struct Silnia{
    enum {
        val = N * Silnia<N - 1>::val
    };
};

template<>   //specjalizacja szablonu
struct Silnia<0>{
    enum {
        val = 1
    };
};


//Nowszy sposób:
/*
template<int N> 
struct Silnia{
    static constexpr int val = N * Silnia<N - 1>::val;
};

template<>   //specjalizacja szablonu
struct Silnia<0>{
    static constexpr int val = 1;
};
*/

/*
template<int N>
constexpr int Silnia(){
    return N * Silnia<N - 1>();
}

template<>
constexpr int Silnia<0>(){
    return 1;
}


//nowsza wersja
constexpr int Silnia(int N){
    return (N == 0)? 1 : N * Silnia(N - 1);
}
*/



int main(int argc, char const *argv[])
{
    
    Silnia<0> silnia0;
    std::cout << "0! == " << silnia0.val << std::endl;

    Silnia<1> silnia1;
    std::cout << "1! == " << silnia1.val << std::endl;

    Silnia<2> silnia2;
    std::cout << "2! == " << silnia2.val << std::endl;


    std::cout << "3! == " << Silnia<3>::val << std::endl;

    std::cout << "4! == " << Silnia<4>::val << std::endl;

    std::cout << "5! == " << Silnia<5>::val << std::endl;
    
    //constexpr int x = Silnia<5>::val ;
    /*
    std::cout << "0! == " << Silnia<0>() << std::endl;
    std::cout << "1! == " << Silnia<1>() << std::endl;
    std::cout << "2! == " << Silnia<2>() << std::endl;
    std::cout << "3! == " << Silnia<3>() << std::endl;
    std::cout << "4! == " << Silnia<4>() << std::endl;
    std::cout << "5! == " << Silnia<5>() << std::endl;

    constexpr int x = Silnia<5>();
    */
    

    /*
    std::cout << "0! == " << Silnia(0) << std::endl;
    std::cout << "1! == " << Silnia(1) << std::endl;
    std::cout << "2! == " << Silnia(2) << std::endl;
    std::cout << "3! == " << Silnia(3)  << std::endl;
    std::cout << "4! == " << Silnia(4)  << std::endl;
    std::cout << "5! == " << Silnia(5) << std::endl;
    */

    

    
    


    return 0;
}


