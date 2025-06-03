#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

/*
Opisz funkcję oraz zastosowanie wzorca projektowego Obserwator, a następnie przedstaw jego implementację w języku C++. 
W swoim opisie uwzględnij, jak wzorzec Obserwator umożliwia komunikację między obiektami w systemie, pozwalając na automatyczne 
powiadamianie i aktualizację zainteresowanych obiektów przy zmianie stanu. 
Zaprezentuj kompletny przykład kodu, który ilustruje jego działanie i sposób użycia w praktycznej aplikacji. 

*/

/*
Obserwator to czynnościowy (behawioralny) wzorzec projektowy pozwalający zdefiniować mechanizm subskrypcji w
celu powiadamiania wielu obiektów o zdarzeniach dziejących się w obserwowanym obiekcie.

Obiekt który posiada jakiś interesujący stan nazywa się zwykle podmiotem, ale skoro będzie powiadamiał inne obiekty o zmianach swojego stanu, można nazwać go publikującym. 
Wszystkie pozostałe obiekty, które chcą śledzić zmiany stanu nadawcy nazywa się subskrybentami.

Wzorzec Obserwator proponuje dodanie mechanizmu subskrypcji do klasy publikującego, 
aby pojedyncze obiekty mogły subskrybować lub przerwać subskrypcję strumienia zdarzeń publikującego.

Zastosowanie:

Stosuj wzorzec Obserwator gdy zmiany stanu jednego obiektu mogą wymagać zmiany w innych obiektach, 
a konkretny zestaw obiektów nie jest zawczasu znany lub ulega zmianom dynamicznie.

Można często natknąć się na ten problem pracując z klasami graficznego interfejsu użytkownika. 
Przykładowo, stworzyliśmy własne klasy przycisków i chcemy aby klienci mogli podpiąć jakiś własny kod do twoich przycisków, a
by uruchamiał się po ich naciśnięciu.


Lista subskrybentów jest dynamiczna, więc subskrybenci mogą zapisać się lub wypisać z listy kiedy chcą.
*/

using namespace std;

// Interfejs dla obserwatorów
class IObserver {
public:
    virtual ~IObserver(){};
    virtual void Update(const std::string &message_from_subject) = 0;
};

// Interfejs dla powiadamiającego (Subject) – obiekt, który powiadamia obserwatorów o zmianach
class ISubject {
public:
    virtual ~ISubject(){};
    virtual void Attach(IObserver *observer) = 0;
    virtual void Detach(IObserver *observer) = 0;
    virtual void Notify() = 0;
};

// Implementacja powiadamiającego
class Subject : public ISubject{
    std::list<IObserver *> list_observer;  
    std::string message{};                  // wiadomość, którą przesyłamy obserwatorom
public:
    virtual ~Subject(){
        std::cout << "Obiekt powiadamiajacy konczy dzialanie." << std::endl;
    }
    virtual void Attach(IObserver *observer){
        list_observer.push_back(observer);
    }
    virtual void Detach(IObserver *observer){
        list_observer.remove(observer);
    }
    virtual void Notify(){        // Powiadomienie wszystkich zapisanych obserwatorów o nowej wiadomości
        HowManyObserver();
        for(auto observer : list_observer)
        {
            observer->Update(message);
        }
    }

    void HowManyObserver(){
        std::cout << "Obecnie mamy: " << list_observer.size() << " obserwatorow (obiektow czekajacych na zdarzenie)" << std::endl;
    }

    void CreateMessage(std::string message){   //operacja tworzenia wiadomosci jest operacją, która musi być zakomunikowana obserwatorom
        this->message = message;
        Notify();
    }


    void SomeBusinessLogic(){    //operacja zmiany wiadomosci jest operacją, która musi być zakomunikowana obserwatorom
        this->message = "change message";
        Notify();
    }

};

// Implementacja obserwatora, który reaguje na zmiany w Subject
class Observer : public IObserver{
    std::string message_from_subject;
    int id_numer;
    static int static_number;
    Subject& subject;
public:
    Observer(Subject& subject) : subject{subject}{              //kazdy obserwator ma instancje powiadamiającego, do którego automatycznie zostaje zapisany
        std::cout << "Stworzono obserwarora numer: " << ++static_number << std::endl;
        id_numer = static_number;
        subject.Attach(this);
    }

    virtual void Update(const std::string &message_from_subject){       //reakcja na powiadomienie
        this->message_from_subject = message_from_subject;
        std::cout << "Obserwator numer: " << id_numer <<" otrzymal powiadomienie od subjecta" << std::endl;
    };

    void RemoveFromTheList(){
        subject.Detach(this);
        std::cout << "Obserwator numer: " << id_numer << " juz nie otrzymuje powiadomien" << std::endl;
    }

    void PrintMessage(){
        std::cout << "Obserwator numer: " << id_numer << " ma wiadomosc: " << message_from_subject << std::endl;
    }

    virtual ~Observer() {
        std::cout << "Obserwator numer: " << id_numer <<  " konczy dzialanie." << std::endl;
    }

};

int Observer::static_number{};






int main(int argc, char const *argv[])
{
    Subject obiekt_powiadamiajacy;

    Observer obserwator1{obiekt_powiadamiajacy};
    Observer obserwator2{obiekt_powiadamiajacy};

    obserwator1.PrintMessage();
    obserwator2.PrintMessage();

    obiekt_powiadamiajacy.CreateMessage("wiadomosc");   //działanie, o którym zajściu powinni dowiedzieć się obserwatorzy

    obserwator1.PrintMessage();
    obserwator2.PrintMessage();

    obserwator1.RemoveFromTheList();

    obiekt_powiadamiajacy.SomeBusinessLogic(); //działanie, o którym zajściu powinni dowiedzieć się obserwatorzy

    obserwator1.PrintMessage();
    obserwator2.PrintMessage();

    return 0;
}
