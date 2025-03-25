/*
Podaj implementacje funkcji max dla różnego typu argumentów. Skorzystaj 
z możliwości przeciążania i specjalizacji szablonów funkcji:
    max(T a, T b)
    max(T *a, T *b)
    max(T *data,size_t n)
    max(char *a,char *a)
    max(const char *a,const char *a)
    max(char *a,const char *a)
*/


#include <iostream>
#include<cstring>

template <typename T>
T max(T a, T b){
    std::cout << "T max(T a, T b)" << std::endl;
    return (a > b)?a:b;
}

template <typename T>
T* max(T *a, T *b){
    std::cout << "T* max(T *a, T *b)" << std::endl;
    return(*a > * b)?a:b;
}

template <typename T>
T max(T * data, std::size_t n){
    std::cout << "T max(T * data, std::size_t n)" << std::endl;
    int max = data[0];
    for (size_t i = 0; i < n; i++)
    {
        if (max < data[1]) max = data[i];
    }
    
    return max;
}

template<>
char * max(char *a, char *b){
    std::cout << "char * max(char *a, char *b)" << std::endl;
    return (strcmp(a, b)>0)?a:b;
}

template<>
const char * max(const char *a,const char *b){
    std::cout << "const char * max(const char *a,const char *b)" << std::endl;
    return (strcmp(a, b)>0)?a:b;
}

template<typename T> 
const T *max(T *a,const T *b) {
    std::cout << "const T *max(T *a,const T *b) " << std::endl;
    return ((*a)>(*b))?a:b;
}

//template<>  const char * max(const char *a, char *b) {cerr<<"S2"<<endl;return (strcmp(a,b)>0)?a:b;}


// Specjalizacja dla char*
template<> 
const char* max(char *a,  const char *b) {
    std::cout << "const char* max(char *a,  const char *b)" << std::endl;
    return (strcmp(a, b) > 0) ? a : b;
}


int main(int argc, char const *argv[])
{
    std::cout << max(4,5) << std::endl;

    int num1 = 6;
    int num2 = 8;
    std::cout << *max(&num1, &num2) << std::endl; 

    int tab[]{4,10,6};
    std::cout << max(tab, 3) << std::endl;

    char slowo1[] = "ananas";
    char slowo2[] = "baran";

    std::cout << max(slowo1, slowo2) << std::endl;

    const char * sl1  = "koala";
    const char * sl2 = "bar";

    std::cout << max(sl1, sl2) << std::endl;


    std::cout << max(slowo1, sl1) << std::endl;

    return 0;
}
