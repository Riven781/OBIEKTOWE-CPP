#include <iostream>

template<size_t N>
constexpr inline double wylicz_iloczyn_skladowych(double *x, double *y){
    return x[N] * y[N];
}

template<size_t N>
constexpr double inner(double *x, double *y){
    return wylicz_iloczyn_skladowych<N - 1>(x, y) + inner<N - 1>(x, y); 
}

template<>
constexpr double inner<0>(double *x, double *y){
    return 0.0; 
}

int main(int argc, char const *argv[])
{
    double x1[]{2.0, 3.0, 4.0};
    double y1[]{5.0, 6.0, 7.0};

    std::cout << inner<3>(x1, y1) << std::endl; // 2*5 + 3*6 + 4*7 = 56


    double x2[]{4.5, -1.3, 2.2};
    double y2[]{0.5, 3.5, 1.0};

    std::cout << inner<3>(x2, y2) << std::endl; //4.5*0.5 + (-1.3)*3.5 + 2.2*1.0 = -0.1


    return 0;
}


