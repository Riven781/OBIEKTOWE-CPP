#include <iostream>

/*


3. Opisz funkcję oraz zastosowanie wzorca projektowego Dekorator, a następnie przedstaw jego implementację w języku C++. 
W swoim opisie uwzględnij, jak wzorzec Dekorator umożliwia dynamiczne dodawanie nowych funkcjonalności do obiektów bez modyfikowania ich kodu źródłowego.
Zaprezentuj kompletny przykład kodu, który ilustruje jego działanie i sposób użycia w praktycznej aplikacji. 
*/

/*
Dekorator to strukturalny wzorzec projektowy pozwalający dodawać nowe obowiązki obiektom poprzez umieszczanie tych obiektów
w specjalnych obiektach opakowujących, które zawierają odpowiednie zachowania.


Pozwala dynamicznie dodawać nowe funkcje do obiektów, bez zmieniania ich kodu.

*/

// INTERFEJS KOMPONENTU – bazowy interfejs dla komponentów i dekoratorów
class Component {
public:
    virtual ~Component() {}
    virtual std::string Operation() const = 0;       // główna operacja, która może być dekorowana
};


class ConcreteComponent : public Component {
public:
    std::string Operation() const override {
        return "ConcreteComponent";
    }
};

// BAZA DLA DEKORATORÓW – dziedziczy po Component i przechowuje wskaźnik na komponent
class Decorator : public Component {
protected:
    Component* component_;        // komponent, który dekorujemy

public:
    Decorator(Component* component) : component_(component) {
    }
    std::string Operation() const override {
        return this->component_->Operation();   // delegujemy operację do komponentu, który dekorujemy
    }
};

// KONKRETNY DEKORATOR A – dodaje własne zachowanie przed/po delegowanej operacji
class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(Component* component) : Decorator(component) {}

    std::string Operation() const override {
        return "ConcreteDecoratorA(" + Decorator::Operation() + ")";
    }
};


// KONKRETNY DEKORATOR B
class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(Component* component) : Decorator(component) {}

    std::string Operation() const override {
        return "ConcreteDecoratorB(" + Decorator::Operation() + ")";
    }
};

void ClientCode(Component* component) {             //używa komponentu bez znajomości jego dekoratorów
  // ...
  std::cout << "RESULT: " << component->Operation();
  // ...
}

int main() {

  Component* simple = new ConcreteComponent;
  std::cout << "Zwykly komponent wyslany do klienta: " << std::endl;
  ClientCode(simple);
  std::cout << "\n\n";

  Component* decorator1 = new ConcreteDecoratorA(simple);
  Component* decorator2 = new ConcreteDecoratorB(decorator1);
  std::cout << "Zwykly udekorowany komponent wyslany do klienta: " << std::endl;
  ClientCode(decorator2);
  std::cout << "\n";

  delete simple;
  delete decorator1;
  delete decorator2;

  return 0;
}