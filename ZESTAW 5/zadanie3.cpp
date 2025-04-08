#include <iostream>

using namespace std;


template <typename T, typename U>
class Is_convertible {
    typedef char one;
    typedef struct {char c[2];} two;

    static one test(U);
    static two test(...);

    static T makeT();

public:
    enum{
        yes = sizeof(test(makeT())) == sizeof(one),
        same_type = false
    };
};

template<typename T>
class Is_convertible <T,T>{
public:
    enum {
        yes = true,
        same_type = true
    };
};

class Klasa{};
class Klasa1 : public Klasa{};
class Klasa2 : public Klasa{};


int main(int argc, char const *argv[])
{
    std::cout << Is_convertible<int, double>::yes << std::endl;
    std::cout << Is_convertible<int, double>::same_type << std::endl;

    std::cout << Is_convertible<int, int>::yes << std::endl;
    std::cout << Is_convertible<int, int>::same_type << std::endl;

    std::cout << Is_convertible<char, int>::yes << std::endl;

    std::cout << Is_convertible<int, char>::yes << std::endl;

    std::cout << Is_convertible<Klasa1, Klasa2>::yes << std::endl;

    std::cout << Is_convertible<Klasa1, Klasa>::yes << std::endl;

    return 0;
}
