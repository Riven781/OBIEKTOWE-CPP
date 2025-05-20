#include <iostream>
#include <vector>
#include <algorithm>
#include <execution>
#include <chrono>
#include <thread>

//g++ zadanie3.cpp -std=c++17 -L/ucrt64/lib -ltbb12 -o zad3.exe

/*
Wybierz 5 różnych algorytmów i przedstaw przykład wykorzystania, w którym równoległe obliczenia przyśpieszą obliczenia proporcjonalnie do ilości występujących w procesorze rdzeni.  
*/

int main() {

    unsigned int cores = std::thread::hardware_concurrency();
    std::cout << "Liczba rdzeni (logicznych): " << cores << std::endl;


    std::vector<int> data(1'000'000, 1);

    auto start = std::chrono::high_resolution_clock::now();


    //Funkcja 1
    std::for_each(std::execution::par, data.begin(), data.end(), [](int &x) {   //wykonuje operację na każdym elemencie zakresu.
        x *= 2; 
    });

    

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> czas_par = end - start;
    std::cout << "Pierwszy element: " << data[0] << "\n";
    std::cout << "Czas wykonania: " << czas_par.count() << " s" << std::endl;



    std::vector<int> input(1'000'000, 2);
    std::vector<int> output(1'000'000);

    start = std::chrono::high_resolution_clock::now();

    //Funkcja 2
    std::transform(std::execution::par, input.begin(), input.end(), output.begin(), [](int x) {  // Przekształca dane z jednego zakresu do innego.
        return x * x;
    });
    
    end = std::chrono::high_resolution_clock::now();
    czas_par = end - start;
    std::cout << "Pierwszy wynik: " << output[0] << "\n";
    std::cout << "Czas wykonania: " << czas_par.count() << " s" << std::endl;
    
    

    std::vector<int> data2(1'000'000);
    std::generate(data2.begin(), data2.end(), std::rand);

    start = std::chrono::high_resolution_clock::now();

    //Funkcja 3
    std::sort(std::execution::par, data2.begin(), data2.end());  //Sortuje elementy.

    end = std::chrono::high_resolution_clock::now();
    czas_par = end - start;

    std::cout << "Posortowano dane.\n";
    std::cout << "Czas wykonania: " << czas_par.count() << " s" << std::endl;

    




    std::vector<int> data3(1'000'000, 1);

    start = std::chrono::high_resolution_clock::now();

    
    //Przykład 4
    int sum = std::reduce(std::execution::par, data3.begin(), data3.end());    // Sumowanie wszystkich elementów wektora 


    end = std::chrono::high_resolution_clock::now();
    czas_par = end - start;

    std::cout << "Suma: " << sum << "\n";
    std::cout << "Czas wykonania: " << czas_par.count() << " s" << std::endl;

    



    std::vector<int> data4(1'000'000);
    std::iota(data4.begin(), data4.end(), 0);

    start = std::chrono::high_resolution_clock::now();

    //Funkcja 3
    size_t count = std::count_if(std::execution::par, data4.begin(), data4.end(), [](int x) {         // Liczy elementy spełniające określony warunek.
        return x % 2 == 0; 
    });

    end = std::chrono::high_resolution_clock::now();
    czas_par = end - start;

    std::cout << "Parzystych liczb: " << count << "\n";
    std::cout << "Czas wykonania: " << czas_par.count() << " s" << std::endl;


}