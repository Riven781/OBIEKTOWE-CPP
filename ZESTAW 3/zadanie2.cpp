/*
Na przykładzie szablonu funkcji convert pokazać, że jest możliwe 
zdefiniowanie dwóch funkcji o tej samej nazwie i argumentach wywołania, 
różniących się tylko zwracanym typem
*/

#include <iostream>
#include <typeinfo>

template<typename T, typename U>
T convert(U u){
    return static_cast<T>(u);
}

template <>
int convert(double u){
    return static_cast<int>(u);
}


template <>
double convert(double u){
    return static_cast<double>(u);
}

int main(int argc, char const *argv[])
{
    std::cout << typeid(convert<int>(3.14)).name() << std::endl;
    std::cout << typeid(convert<double>(3)).name() << std::endl;
    return 0;
}
