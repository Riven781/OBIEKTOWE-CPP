#include <iostream>
#include <string>
#include <memory>
#include <vector>

/*
Zaimplementuj szablon funkcji SongFactory tak aby obiekt ‘song’ był wskaźnikiem typu unique_ptr dla obiektów klasy Song

auto song = SongFactory(L"Michael Jackson", L"Beat It");

oraz przedstaw działanie konstruktora i destruktora obiektu przechowywanego przez wskaźnik
we wnętrzu inteligentnego wskaźnika. Wypełnij std::vector<std::unique_ptr<Song>> songs i pokaż, 
że zakresowa pętla „for” musi wykorzystywać referencje. 

*/

using namespace std;

class Song
{
private:
    std::wstring artist;
    std::wstring title;
public:
    Song(std::wstring artist, std::wstring title) : artist{artist}, title{title}{
        std::wcout << L"Tworzenie piosenki: " << artist << L" - " << title << std::endl;
    };
    ~Song(){
        std::wcout << L"Usuwanie piosenki: " << artist << L" - " << title << std::endl;
    };
    void display(){
        std::wcout << title << L" - " << title << std::endl;
    }
};

//funkcja, który tworzy i zwraca wskaźnik typu unique_ptr do obiektu klasy Song
std::unique_ptr<Song> SongFactory(const wstring& artist, const wstring& title){
    return make_unique<Song>(artist, title);   //zwraca wskaźnikiem typu unique_ptr dla obiektów klasy Song
}


int main(int argc, char const *argv[])
{
    
    std::vector<unique_ptr<Song>> songs;

    songs.push_back(SongFactory(L"Michael Jackson",  L"Beat It"));
    songs.push_back(SongFactory(L"B'z", L"Juice"));
    songs.push_back(SongFactory(L"Namie Amuro", L"Funky Town"));
    songs.push_back(SongFactory(L"Kome Kome Club", L"Kimi ga Iru Dake de"));
    songs.push_back(SongFactory(L"Ayumi Hamasaki", L"Poker Face"));


    //używam referencji (&), aby nie kopiować obiektów
    for (auto& song: songs){
        song->display();
    }


    return 0;
}
