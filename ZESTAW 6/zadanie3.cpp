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


//Szablon typu Allocator_policy posiada jeden typ stowarzyszony i szereg funkcji
template<typename T, size_t N = 0>
struct static_table_allocator
{
    typedef T rep_type[N];                           //alisat tablicy N elementowej
    void init(rep_type &,size_t) {};
    void expand_if_needed(rep_type &,size_t) {};
    void shrink_if_needed(rep_type &,size_t) {};
    void dealocate(rep_type &){};

    static size_t size() {return N;};
};

template<typename T, size_t N = 0>
struct dynamic_table_allocator
{
    typedef T* rep_type;                           
    size_t _size;
    void init(rep_type & tab,size_t n) {
        _size = n;
        tab = new T[_size];
    }
    void expand_if_needed(rep_type & tab,size_t top) {
        /*if (top == _size){
            _size = 2 * _size;
            T* tmp = new T[_size];
            std::copy(tab, &tab[top], tmp);
            delete [] tab;
            tab = tmp;
        }*/

    }
    void shrink_if_needed(rep_type &,size_t) {};
    void dealocate(rep_type & tab){
        delete [] tab;
    };

    size_t size() {return _size;};
};



template <typename T = int, size_t N = 100, typename checking_policy = no_checking_policy, template<typename U, size_t M> class allocator_policy = static_table_allocator>
class Stack{
    typedef typename allocator_policy<T,N>::rep_type rep_type;
    rep_type tab;
    size_t top_index;
    allocator_policy<T,N> alloc;
public:
    Stack(size_t n =  N) : top_index{0} {
        alloc.init(tab, n);
    };

    void push(const T& element){ 
        alloc.expand_if_needed(tab, top_index);
        checking_policy::check_push(top_index, N);

        tab[top_index++] = element; 
    }

    void pop() { 
        checking_policy::check_pop(top_index);
        --top_index; 
        alloc.shrink_if_needed(tab,top);
    
    }

    const T& top(T element){ 
        return tab[top_index - 1]; 
    }

    bool is_empty() { 
        checking_policy::check_top(top_index);
        return !top_index;
    }

    void display();

    ~Stack(){
        alloc.dealocate(tab);
    }

};

template <typename T, size_t N, typename checking_policy, template<typename U, size_t M> class allocator_policy > 
void Stack<T,N, checking_policy, allocator_policy>::display(){
    for (size_t i = 0; i < top_index; i++)
    {
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    Stack<int, 2, no_checking_policy, static_table_allocator> stos;

    stos.push(5);
    stos.push(6);

    stos.display();

    Stack<int, 2, std_exception_on_error_policy, dynamic_table_allocator> stos2;

    stos2.push(8);
    stos2.push(7);


    stos2.display();

    return 0;
}
