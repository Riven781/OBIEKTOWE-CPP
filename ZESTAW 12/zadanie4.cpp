#include <iostream>
#include <algorithm>


/*
Opisz funkcję oraz zastosowanie wzorca projektowego Adapter, a następnie przedstaw jego implementację w języku C++. 
W swoim opisie uwzględnij, jak wzorzec Adapter umożliwia współpracę między klasami o niekompatybilnych interfejsach 
poprzez przekształcanie jednego interfejsu na inny. 
Zaprezentuj kompletny przykład kodu, który ilustruje jego działanie i sposób użycia w praktycznej aplikacji. 

*/


/*
Adapter jest strukturalnym wzorcem projektowym pozwalającym na współdziałanie ze sobą obiektów o niekompatybilnych interfejsach.

Stosuj klasę Adapter gdy chcesz wykorzystać jakąś istniejącą klasę, ale jej interfejs nie jest kompatybilny z resztą twojego programu.

Zastosowania:
- Integracja z biblioteką zewnętrzną:
Masz bibliotekę, która zwraca dane lub posiada metody inaczej nazwane niż twoje klasy. 
Nie chcesz modyfikować biblioteki, więc tworzysz adapter, który dostosowuje interfejs.

- Stare i nowe API:
Masz nowy system, który używa innego formatu lub metod niż stary system. Adapter pozwala na kompatybilność obu systemów.

- Praca z różnymi formatami danych:
Klient oczekuje danych w formacie X, a klasa dostarcza w formacie Y. Adapter zamienia dane z formatu Y na X.



*/

// Klasa docelowa (Target) – interfejs, który klient potrafi obsłużyć
class Target {
public:
    virtual ~Target() = default;

    virtual std::string Request() const {                  // Domyślna implementacja metody, którą klient wywołuje
        return "Target: The default target's behavior.";
    }
};

// Klasa Adaptee – posiada funkcjonalność, ale w innej formie (inny interfejs)
class Adaptee {
public:
    std::string SpecificRequest() const {   // // Zwraca ciąg znaków w odwróconej kolejności
        return ".eetpadA eht fo roivaheb laicepS";
    }
};

// Adapter dziedziczy po Target i tłumaczy interfejs Adaptee na zrozumiały dla klienta
class Adapter : public Target {
private:
    Adaptee *adaptee_;

public:
    Adapter(Adaptee *adaptee) : adaptee_(adaptee) {}
    std::string Request() const override {
        std::string to_reverse = this->adaptee_->SpecificRequest();
        std::reverse(to_reverse.begin(), to_reverse.end());
        return "Adapter: (TRANSLATED) " + to_reverse;
    }
};


void ClientCode(const Target *target) {
    std::cout << target->Request();
}

int main() {
    std::cout << "Klient pracuje z obiektami Target:" << std::endl;
    Target *target = new Target;
    ClientCode(target);
    std::cout  << std::endl;
    Adaptee *adaptee = new Adaptee;   //klient nie rozumie tejgo interfejsu
    std::cout << "Adaptee: " << adaptee->SpecificRequest() << std::endl;

    std::cout << "Klient moze wspolpracwac z klasa Adaptee dzieki Adapterowi" << std::endl;
    Adapter *adapter = new Adapter(adaptee);
    ClientCode(adapter);


    delete target;
    delete adaptee;
    delete adapter;

    return 0;
}