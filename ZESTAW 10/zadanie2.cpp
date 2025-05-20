#include <vector>  
#include <algorithm>  
#include <execution>  
#include <mutex>  
#include <iostream>

//g++ zadanie2.cpp -std=c++17 -L/ucrt64/lib -ltbb12 -o zad2.exe

/*
Wykorzystując std::lock_guard zmodyfikuj lambda expression tak aby nie dochodziło do niezsynchronizowanego dostępu do wektora wyjściowego. 
Porównaj wydajność przy wykorzystaniu polityki typu seq.  
*/


int main() { 
    
    std::mutex mtx; 
    std::vector<int> vec(10'000'000);   
    std::iota(vec.begin(), vec.end(), 0);   
    std::vector<int> output;   

    auto start = std::chrono::high_resolution_clock::now();

    std::for_each(std::execution::par, vec.begin(), vec.end(),  

        [&output, &mtx](int& elem) {       
            if (elem % 2 == 0) {           
                std::lock_guard<std::mutex> quard(mtx);   // Blokujemy mutex — tylko jeden wątek może wejść do tej sekcji naraz
                output.push_back(elem);  
            }  

        });  
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> czas_par = end - start;

    std::cout << "Wynik rownolegly (z mutexem): " << output.size() << " elementow, czas: " 
              << czas_par.count() << " s\n";


    output.clear();


        start = std::chrono::high_resolution_clock::now();

    std::for_each(std::execution::seq, vec.begin(), vec.end(),
        [&output](int elem) {
            if (elem % 2 == 0) {
                output.push_back(elem);
            }
        });

    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> czas_seq = end - start;

    std::cout << "Wynik sekwencyjny: " << output.size() << " elementow, czas: " 
              << czas_seq.count() << " s\n";

}  

/*
W konstruktorze std::lock_guard blokuje przekazany std::mutex (czyli wywołuje mtx.lock()).

W destruktorze odblokowuje go (mtx.unlock()), automatycznie, gdy obiekt lock_guard wychodzi z zakresu.
*/