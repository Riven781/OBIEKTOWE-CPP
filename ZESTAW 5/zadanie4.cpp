#include <iostream>
#include <type_traits>
#include <typeinfo>
using namespace std;

template<typename T>
struct Strip{
    typedef T arg_type;
    typedef T striped_t;
    typedef T base_t;
    typedef const T const_type;

    typedef T& ref_type;
    typedef T& ref_base_type;
    typedef const T & const_ref_type;

};

template<typename T>
struct Strip <T const>{
    typedef const T arg_t;
    typedef T striped_t;
    typedef typename Strip<T>::base_t base_t;
    typedef T const const_type;

    typedef T const & ref_type;
    typedef T & ref_base_type;
    typedef T const & const_ref_type;

};

template<typename T> 
struct Strip<T&> {
    typedef T& arg_t;
    typedef T  striped_t;
    typedef typename Strip<T>::base_t  base_t;
    typedef base_t const    const_type;
  
    typedef T ref_type;
    typedef base_t & ref_base_type;
    typedef base_t const &  const_ref_type;
};




int main(int argc, char const *argv[])
{
    static_assert(std::is_same<Strip<int>::ref_type, int&>::value, "ref_type should be int&");
    static_assert(std::is_same<Strip<const double>::ref_type, const double&>::value, "ref_type should be const double&");
    static_assert(std::is_same<Strip<int&>::ref_type, int>::value, "ref_type should be int");

    static_assert(std::is_same<Strip<int&>::ref_base_type, int&>::value, "ref_base_type should be int&");
    static_assert(std::is_same<Strip<int&>::const_ref_type, const int&>::value, "const_ref_type should be const int&");
    
    return 0;
}
