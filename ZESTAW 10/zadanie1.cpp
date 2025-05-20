#include <iostream>
#include <vector>
#include <algorithm>
#include <execution>
#include <chrono>
//#include <tbb/tbb.h>

//g++ zadanie1.cpp -std=c++17 -L/ucrt64/lib -ltbb12 -o zad1.exe

/*

Opisz wykorzystując funkcjonalne przykłady występujące w C++17 execution policy  :  

std::execution::sequenced_policy,  std::execution::parallel_policy  

std::execution::parallel_unsequenced_policy,  

*/

using namespace std;

template <typename ExecutionPolicy>
void compare_execution_policy(ExecutionPolicy & policy){
    vector<int> vec;

    const size_t N = 10;

    for (size_t i = 0; i < N; i++)
    {
        vec.push_back(i);
    }

    auto start = std::chrono::high_resolution_clock::now();

    for_each(policy, vec.begin(), vec.end(), [](int x) {  //  // Wykonujemy operację na wszystkich elementach wektora z użyciem wybranej polityki wykonania
        x *= 2;
        std::cout << x << std::endl;
    } );

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration<double>(end - start).count();

    std::cout  << "Wykonano w: " << duration << " sekundy\n";
}



int main(int argc, char const *argv[])
{
    compare_execution_policy<>(std::execution::seq);               //Wymusza sekwencyjne (jednowątkowe) wykonywanie algorytmu 
    compare_execution_policy<const std::execution::parallel_policy>(std::execution::par);   //Zapewnia, że operacje będą wykonywane w sposób równoległy, ale również gwarantuje, że operacje będą wykonywane w określonej kolejności (odpowiednio do kolejności w algorytmie).
    compare_execution_policy<>(std::execution::par_unseq);       //Zapewnia, że operacje będą wykonywane w sposób równoległy, ale nie gwarantuje żadnej kolejności. Operacje mogą być wykonywane w dowolnej kolejności przez wątki.
   
    return 0;
}
