#include <iostream>

template <typename T>
struct sum_traits{
    typedef T sum_type;
};

template <>
struct sum_traits<int>{
    typedef long int sum_type;
};

template <>
struct sum_traits<char>{
    typedef int sum_type;
};

template <>
struct sum_traits<float>{
    typedef double sum_type;
};

/*
template <>
struct sum_traits<double>{
    typedef double sum_type;
};
*/
template <typename T>
typename sum_traits<T>::sum_type sum(T* beg, T* end){
    typedef typename sum_traits<T>::sum_type sum_type;
    sum_type total = sum_type();
    while (beg != end)
    {
        //std::cout << *beg << std::endl;
        total += *beg;
        ++beg;
    }
    return total;
}

int main(int argc, char const *argv[])
{
    char slowo[] = "abc"; //a = 97, b = 98, c = 99
    std::cout << "Dla char: " << sum(slowo, &slowo[4]) << std::endl;

    int liczby_int[]{5,6,7,8,9,10}; //suma 45
    std::cout << "Dla int: " << sum(liczby_int, &liczby_int[6]) << std::endl;

    float liczby_float[]{4.5,10.4,6.2}; //suma 21.1
    std::cout << "Dla float: " << sum(liczby_float, &liczby_float[3]) << std::endl;

    float liczby_double[]{5.78,9.3,0.5}; //suma 15.58
    std::cout << "Dla double: " << sum(liczby_double, &liczby_double[3]) << std::endl;
    
    return 0;
}


