#include <iostream>
#include <memory>
#include <string>


/*
template< class T, class... Args > 
unique_ptr<T> make_unique( Args&&... args );

Ta wersja umożliwia tworzenie obiektów typu T za pomocą konstruktorów wymagających parametrów. 
Możemy przekazać dowolną liczbę argumentów do konstruktora obiektu, a funkcja 
std::make_unique zajmuje się stworzeniem obiektu oraz opakowaniem go w std::unique_ptr. 
Parametry, które zostaną przekazane do funkcji, są dalej przekazywane do konstruktora obiektu typu T.
class... Args <---- oznacza szablon o zmiennej liczbie argumentów
oznacza, że szablon przyjmuje dowolny typ T oraz zmienną liczbę argumentów typu Args

template< class T > 
unique_ptr<T> make_unique( std::size_t size );

Ta wersja funkcji jest używana, gdy chcemy utworzyć dynamiczną tablicę obiektów typu T.
Funkcja przyjmuje jeden argument — rozmiar tablicy (liczba elementów), a następnie alokuje pamięć dla tej tablicy.
*/
struct Object
{
    int j;
    double k;
    std::string text;
    Object(int j, double k, std::string text) : j{j}, k{k}, text{text}{};
    Object() : j{}, k{}, text{"---"}{};
};


int main(int argc, char const *argv[])
{
    auto ptr_obj = std::make_unique<Object>(10, 3, "tekst");    // Tworzenie pojedynczego obiektu Object

    std::cout << ptr_obj->text << std::endl;

    auto ptr = std::make_unique<Object[]>(5);       // Tworzenie tablicy 5 obiektów Object (z domyślnym konstruktorem)

    for (int i = 0; i < 5; ++i) {
        std::cout << "Object " << i << ": " << ptr[i].text << std::endl;
    }

    //std::unique_ptr<Object[]> ptr = std::make_unique<Object[]>(5);
    
    return 0;
}


