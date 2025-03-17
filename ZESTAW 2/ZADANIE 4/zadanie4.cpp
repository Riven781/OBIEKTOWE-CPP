#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

template<typename T> class SequenceGen {
    private:
      T _start; 
      T _step;
    public:
      SequenceGen(T start = T(),T step = 1 ):
      _start(start),_step(step){};
    
      T operator()() {T tmp=_start; _start+=_step; return tmp;}
};

int main() {
    std::vector<int> vec(20);
    std::generate_n(vec.begin(), 20, SequenceGen(1,2));
    
    std::cout << "Wektor: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << "\n";
    
    auto it = std::find_if(vec.begin(), vec.end(), std::bind(std::greater<int>(), std::placeholders::_1, 4));
    
    //auto it = std::find_if(vec.begin(), vec.end(), [](int x) { return x > 4; });

    if (it != vec.end()) {
        std::cout << "Pierwszy element większy od 4: " << *it << "\n";
    } else {
        std::cout << "Nie znaleziono elementu wiekszego od 4.\n";
    }
    
    return 0;
}
