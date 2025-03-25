/*
Zapoznaj się z rodziną funktorów porównujących, do której należą np. 
less<>()  --- <, greater<>() ---- >, less_equal<>() --- <=, greater_equal<>() --- >=. Przypomnij 
sobie pojemnik std::set. Następnie napisz programik korzystający ze zbioru 
liczb posortowanego odwrotnie (czyli malejąco).

*/

#include <iostream>
#include <set>

using namespace std;

int main(int argc, char const *argv[])
{
    set<int, greater<int>> numbers = {5,7,2,3,4,10};
    numbers.insert(12);
    numbers.insert(0);

    for (auto element : numbers)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    

    return 0;
}
