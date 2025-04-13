#include <iostream>



struct no_checking_policy {
    static void check_push(size_t, size_t) {};
    static void check_pop(size_t) {};
    static void check_top(size_t) {};
};

struct abort_on_error_policy{
    static void check_push(size_t top_index, size_t size){
        if (top_index >= size){
            std::cout << "trying to push elemnt on full stack: aborting" << std::endl;
            abort();
        }
    }

    static void check_pop(size_t top_index){
        if (top_index == 0){
            std::cout << "trying to pop an empty stack: aborting" << std::endl;
            abort();
        }
    }

    static void check_top(size_t top_index){
        if (top_index == 0){
            std::cout << "trying to read from empty stack: aborting" << std::endl;
            abort();
        }
    }
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



template <typename T = int, size_t N = 100, typename checking_policy = no_checking_policy> 
class Stack {
    T tab[N];
    size_t top_index;
public:
    Stack() : top_index{0} {}

    void push(const T& element){ 
        checking_policy::check_push(top_index, N);

        tab[top_index++] = element; 
    }

    void pop() { 
        checking_policy::check_pop(top_index);
        --top_index; }

    const T& top(T element){ return tab[top_index - 1]; 
    }

    bool is_empty() { 
        checking_policy::check_top(top_index);
        return !top_index;
    }

    void display();

};



template <typename T, size_t N, typename checking_policy > 
void Stack<T,N, checking_policy>::display(){
    for (size_t i = 0; i < top_index; i++)
    {
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;
}


int main(int argc, char const *argv[])
{
    Stack<int,3, abort_on_error_policy> stos;

    stos.push(10);
    stos.push(12);
    stos.push(14);
//    stos.push(16);

    stos.display();

    Stack<int,2, std_exception_on_error_policy> stos2;

    stos2.push(1);
    stos2.push(2);
//    stos2.push(3);

    

    return 0;
}
