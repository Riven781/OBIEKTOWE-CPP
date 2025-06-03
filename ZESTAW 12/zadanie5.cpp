#include <iostream>
#include <array>

/*
Opisz funkcję oraz zastosowanie wzorca projektowego Visitor (Odwiedzający), a następnie przedstaw jego implementację w języku C++. 
W swoim opisie uwzględnij, jak wzorzec Visitor umożliwia dodawanie nowych operacji do klas bez modyfikowania ich kodu, 
poprzez separację algorytmu od struktury obiektów. 
Zaprezentuj kompletny przykład kodu, który ilustruje jego działanie i sposób użycia w praktycznej aplikacji. 

Odwiedzający to behawioralny wzorzec projektowy pozwalający oddzielić algorytmy od obiektów na których pracują.

*/

class ConcreteComponentA;
class ConcreteComponentB;

// Interfejs Visitor definiujący operacje dla konkretnych typów komponentów
class Visitor {
public:
    virtual void VisitConcreteComponentA(const ConcreteComponentA *element) const = 0;
    virtual void VisitConcreteComponentB(const ConcreteComponentB *element) const = 0;
};


// Abstrakcyjny komponent, który akceptuje odwiedzającego (Visitor)
class Component {
    public:
    virtual ~Component() {}
    virtual void Accept(Visitor *visitor) const = 0;
};

// Konkretna implementacja komponentu A
class ConcreteComponentA : public Component {
    public:
    void Accept(Visitor *visitor) const override {
        visitor->VisitConcreteComponentA(this);
    }
   
    std::string ExclusiveMethodOfConcreteComponentA() const {
        return "A";
    }
};

// Konkretna implementacja komponentu B
class ConcreteComponentB : public Component {
public:
    void Accept(Visitor *visitor) const override {   
        visitor->VisitConcreteComponentB(this);             // Komponent przekazuje siebie odwiedzającemu, wywołując właściwą metodę
    }
    std::string SpecialMethodOfConcreteComponentB() const {
        return "B";
    }
};

// Konkretna implementacja odwiedzającego (Visitor 1)
class ConcreteVisitor1 : public Visitor {
    public:
    void VisitConcreteComponentA(const ConcreteComponentA *element) const override {
        std::cout << element->ExclusiveMethodOfConcreteComponentA() << " + ConcreteVisitor1\n";    //dla danego (każdego) komponentu wyswietla wiadomość składającą się ze stringa zwroconego przez metode komponentu (ExclusiveMethodOfConcreteComponentA) i dopisanego: "ConcreteVisitor1"
    }

    void VisitConcreteComponentB(const ConcreteComponentB *element) const override {
        std::cout << element->SpecialMethodOfConcreteComponentB() << " + ConcreteVisitor1\n";
    }
};

// Konkretna implementacja odwiedzającego (Visitor 2)
class ConcreteVisitor2 : public Visitor {
public:
    void VisitConcreteComponentA(const ConcreteComponentA *element) const override {
        std::cout << element->ExclusiveMethodOfConcreteComponentA() << " + ConcreteVisitor2\n";
    }
    void VisitConcreteComponentB(const ConcreteComponentB *element) const override {
        std::cout << element->SpecialMethodOfConcreteComponentB() << " + ConcreteVisitor2\n";
    }
};


void ClientCode(std::array<const Component *, 2> components, Visitor *visitor) {
    for (const Component *comp : components) {
        comp->Accept(visitor);
    }

}

int main() {
    std::array<const Component *, 2> components = {new ConcreteComponentA, new ConcreteComponentB};

    ConcreteVisitor1 *visitor1 = new ConcreteVisitor1;
    ClientCode(components, visitor1);

    ConcreteVisitor2 *visitor2 = new ConcreteVisitor2;
    ClientCode(components, visitor2);

    for (const Component *comp : components) {
        delete comp;
    }
    delete visitor1;
    delete visitor2;

    return 0;
}