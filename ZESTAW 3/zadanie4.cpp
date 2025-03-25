/*
Zaimplementować szablon klasy Stack wraz z jej specjalizacjami tak aby 
„działała” ze zwykłymi tablicami oraz kontenerami STL:
Stack<int,100> s_default ;
Stack<int,0,std::vector<int> > s_container;
*/


#include <iostream>
#include <vector>

template<typename T, int N, typename R = T*> class Stack;

template<typename T, int N> 
class Stack<T,N,T*>{
    T _rep[N];
    unsigned int _top;
public:
    Stack(): _top{0}{
        std::cout << "Utworzono Stack<T,N,T*>" << std::endl;
    };
    void push(T e){
        _rep[_top++] = e;
    }
    T pop(){
        return _rep[--_top];
    }
};


template<typename T, int N, template<typename E> class Sequence> 
class Stack<T,N,Sequence<T>>{
    Sequence<T> _rep;
public:
    Stack(){
        std::cout << "Utworzono Stack<T,N,Sequence<T>>" << std::endl;
    };
    void push(T e){
        _rep.push_back(e);
    }
    T pop(){
        T top = _rep.top();
        _rep.pop_back();
        return top;
    }
};

int main(int argc, char const *argv[])
{
    Stack<int, 100, int *> s_tab;
    Stack<int, 100, std::vector<int> > s_vec; 
    return 0;
}
