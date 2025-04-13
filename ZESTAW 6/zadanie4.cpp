#include <iostream>

struct no_checking_policy {
    static void check_push(size_t, size_t) {};
    static void check_pop(size_t) {};
    static void check_top(size_t) {};
};

struct std_exception_on_error_policy
{
    static void check_push(size_t top_index, size_t size){
        if (top_index >= size){
            throw std::range_error("over the top");
        }
    }

    static void check_pop(size_t top_index){
        if (top_index == 0){
            throw std::range_error("poping empty");
        }
    }

    static void check_top(size_t top_index){
        if (top_index == 0){
            throw std::range_error("reading empty");
        }
    }
};


template<typename T, size_t N = 0>
struct static_table_allocator
{
protected:
    typedef T rep_type[N];                           //alisat tablicy N elementowej
    rep_type tab;
    void init(size_t) {};
    void expand_if_needed(size_t ) {};
    void shrink_if_needed(size_t) {};
    void dealocate(){};

    static size_t size() {return N;};
};



template<typename T, size_t N = 0>
struct dynamic_table_allocator
{
protected:
    typedef T* rep_type;    
    rep_type tab;                       
    size_t _size;
    void init(size_t n) {
        _size = n;
        tab = new T[_size];
    }
    void expand_if_needed(size_t top) {
        resize(_size * 2);
    }
    void shrink_if_needed(size_t) {}
    void dealocate(){
        delete [] tab;
    };
    size_t size() {return _size;};
public:
  void resize(size_t n) {
    T *tmp= new T[n];
    std::copy(tab,&tab[(_size<n)?_size:n],tmp);
    delete [] tab;
    tab = tmp;
    _size=n;
  }
};

template<typename T = int, size_t N = 100, typename checking_policy = no_checking_policy, template<typename U, size_t M> class allocator_policy = static_table_allocator>
class Stack : private checking_policy, private allocator_policy<T,N>{
    size_t top_index = 0;



    public:
    Stack(size_t n =  N) : top_index{0} {
        allocator_policy<T,N>::init(n);   //lub this->init(tab, n);
    };

    void push(const T& element){ 
        this->expand_if_needed(top_index);
        checking_policy::check_push(top_index, this->size());

        this->tab[top_index++] = element;

    }

    void pop() { 
        checking_policy::check_pop(top_index);
        --top_index; 
        allocator_policy<T,N>::shrink_if_needed(top_index);
    
    }

    const T& top(T element){ 
        checking_policy::check_top(top_index); 
        return this->tab[top_index - 1]; 
    }

    bool is_empty() { 
        return !top_index;
    }

    //void display();

    ~Stack(){
        allocator_policy<T,N>::dealocate();
    }

    
};


int main(int argc, char const *argv[])
{
    Stack<int, 2, std_exception_on_error_policy, dynamic_table_allocator> stos;

    stos.push(5);
    stos.push(6);


    stos.push(7);   //można bo w linijce 59 tablica zostala powiekszona, a polityka zakresu dostaje powiekszony size, dlatego nie ma bledu
    
    return 0;
}
