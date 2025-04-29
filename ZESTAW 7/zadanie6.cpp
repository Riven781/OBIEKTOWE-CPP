#include <iostream>



template<size_t N, typename T> T dot(T *x, T *y){
    return   dot<0, T>::val;
}



template<size_t N, typename T>
struct dot{
    static constexpr T* x{};
    static constexpr T* y{}; 

    static constexpr T val = x[N - 1] * y[N - 1] + dot<N - 1, T>::val;
};

template<size_t N, typename T>
struct dot<0, T>{
    static constexpr T val = T();
};




/*

template <size_t N, typename T>
T inner(T *x, T *y) {
    return (N == 0) ? T() : (x[N - 1] * y[N - 1] + inner<N - 1, T>(x, y));
}

*/


int main(int argc, char const *argv[])
{
    int x1[]{2, 3, 4};
    int y1[]{5, 6, 7};
    dot<3, int>(x1, y1);
   // std::cout << << std::endl; // 2*5 + 3*6 + 4*7 = 56

    /*
    
    double x2[]{4.5, -1.3, 2.2};
    double y2[]{0.5, 3.5, 1.0};

    std::cout << inner<3, double>(x2, y2) << std::endl; // 4.5*0.5 + (-1.3)*3.5 + 2.2*1.0 = -0.1
    
    */
    

    return 0;
}
