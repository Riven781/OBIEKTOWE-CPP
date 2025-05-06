#include <iostream>

using namespace std;




template <typename T>
class is_class{
    typedef char one;
    typedef struct{char c[2];} two;

    template<typename U>
    static one test(int U::*);
    template<typename U>
    static two test(...);

public:
    enum {
        yes = (sizeof(test<T>(nullptr)) == sizeof(one)) 
    };
};






/*


template<typename T> class is_class {
    typedef char one;
    typedef struct {char c[2];} two;
  
    static one test(int T::*);    //nie działa bo nie gdy T jest int no to ta funckja zgłasza błąd kompilacji
    static two test(...);
  
  public:
    static constexpr bool yes = (sizeof(test(0)) == sizeof(one));
};

*/





struct struktura{};

class Klasa{};

int main(int argc, char const *argv[])
{

    static_assert(::is_class<int>::yes == 0);

    std::cout << ::is_class<int>::yes << std::endl;
    std::cout << ::is_class<struktura>::yes << std::endl;
    std::cout << ::is_class<Klasa>::yes << std::endl;
    std::cout << ::is_class<int[]>::yes << std::endl;
    std::cout << ::is_class<float *>::yes << std::endl;
   
    return 0;
}
