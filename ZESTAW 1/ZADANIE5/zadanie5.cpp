#include <vector>
#include <iostream>
#include <cassert>
#include <string>

template <typename T, size_t N = 100> class Stack{
    private:
        std::vector<T> _rep;
        size_t _top;
    public:
        typedef T value_type;
        Stack():_top(0), _rep(N) {};
        void push(T val) {
            _rep[_top++]=val;}
        T pop() {return _rep[--_top];}
        bool is_empty() {return (_top==0);} 

};


template <typename S> typename S::value_type f(S s){
    typename S::value_type total =  typename S::value_type();
    while (!s.is_empty())
    {
        total += s.pop();
    }
    return total;
}


void test(){
    Stack<int, 4> stos;
    stos.push(5);
    stos.push(8);
    stos.push(1);

    assert(f(stos) == 14);

    std::cout << "Total: " << f(stos) << std::endl;

    Stack<std::string, 3> stos2;
    stos2.push("ania");
    stos2.push("asia");
    stos2.push("basia");

    std::cout << "Total: " << f(stos2) << std::endl;

    assert(f(stos2) == "basiaasiaania");

}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}
