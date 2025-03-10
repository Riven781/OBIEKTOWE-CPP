#include <iostream>
#include <cassert>

using namespace std;

template <size_t N, typename T>T dot_product(T *a, T *b){
    T total = 0.0;
    for (size_t i = 0; i<N; ++i){
        total += a[i] * b[i];
    }
    return total;
}


void test(){
    double x[3] = {1.0, 2.0, 3.0};
    double y[3] = {4.0, 5.0, 6.0};
    assert(dot_product<3>(x,y) == 32);
    
    std::cout << dot_product<3>(x,y) << std::endl;
}


int main(int argc, char const *argv[])
{
    test();
    return 0;
}
