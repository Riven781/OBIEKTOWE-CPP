#include <iostream>
#include <string>

/*
Opisz funkcję oraz zastosowanie wzorca projektowego Singleton, a następnie przedstaw jego implementację w języku C++. 
W swoim opisie uwzględnij wyjaśnienie, dlaczego wzorzec ten jest użyteczny, 
jakie problemy rozwiązuje oraz zaprezentuj kompletny przykład kodu, który ilustruje jego działanie i sposób użycia w praktycznej aplikacji.

*/

/*
Singleton jest kreacyjnym wzorcem projektowym, który pozwala zapewnić istnienie wyłącznie jednej instancji danej klasy. 
Ponadto daje globalny punkt dostępowy do tejże instancji.

Zastosowanie:
- Przykładem może być połączenie z bazą danych, którego używa wiele fragmentów programu.

*/

class Singleton{
private:
    std::string val;
    Singleton(std::string value) : val{value}{
        std::cout << "Tworze obiekt" << std::endl;
    };
    static Singleton* ptr_instance;   //// Wskaźnik do jedynej instancji klasy Singleton
public:
    
    static Singleton* getInstance(const std::string& value){  // Metoda statyczna zwracająca instancję klasy Singleton (tworzy lub zwraca)
        if (ptr_instance == nullptr){
            ptr_instance = new Singleton(value);
        }
        return ptr_instance;
    }
    static void destroyInstance() {    // Metoda do zniszczenia instancji i zwolnienia pamięci
        delete ptr_instance;
        ptr_instance = nullptr;
    }

    std::string getValue() const {
        return val;
    }

    Singleton(Singleton &other) = delete;  //zapobiega kopiowaniu instancji (usunięcie konstruktora kopiującego)
    void operator=(const Singleton &) = delete;  //zapobiega przypisywaniu jednej instancji do drugiej  (Usunięcie operatora przypisania)
};

Singleton* Singleton::ptr_instance{nullptr};

int main(int argc, char const *argv[])
{
    Singleton* singleton = Singleton::getInstance("nr1");

    Singleton* singleton2 = Singleton::getInstance("nr2");

    std::cout << singleton->getValue() << std::endl;
    std::cout << singleton2->getValue() << std::endl;

    if (singleton == singleton2) {
        std::cout << "s1 i s2 to ta sama instancja!" << std::endl;
    }

    return 0;
}
