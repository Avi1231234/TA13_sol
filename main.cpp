#include <iostream>
#include "GenericPair.h"
#include <vector>

// TODO 1a. change get_max to a generic templated func
template<class T> //anything that is templated needs this keyword. class and typename in this context are the same
T get_max(const T a, const T b)
{
    T ret_val = a > b? a: b;
    //TODO 1c. Add a static variable which counts the amount of times get_max
    // has been called. What can we say about the amount of times the
    // function was called per instantiation?
    static int count;
    count++;
    std::cout << "count is: " << count << std::endl;
    return ret_val;
}

// TODO: 3b Specialize get_max so that for strings it returns the longer
//  string instead.
using std::string;
template<>
string get_max(const string a, const string b)
{
    return  a.length() > b.length() ? a : b;
}

// TODO: 2a  write print_char func that prints a generic type (default is
//  char) and gets a bool parameter without it being sent as argument.
template<class T = char, int end_line = true>
void print_char(T var)
{
    std::cout<< "var is " << var;
    if(end_line)
    {
        std::cout << std::endl;
    }
}

void pair_test()
{
    GenericPair<int> int_var(10,20);
    GenericPair<double> double_var(1.5,2.5);

    std::cout << int_var.get_count() << std::endl;

    GenericPair<int> int_var2 = int_var;
    std::cout << int_var2.get_count() << std::endl;
}

int main()
{
    //TODO 1b. call get_max on int and strings:
    auto x = get_max(4,5);
    auto y = get_max('c', 't');
    std::cout << "max of the integers is: " << x << std::endl;
    std::cout << "max of the characters is: " << y << std::endl;

    //TODO 2b. call print_char with char once with and without endl
    print_char('c');
    print_char<char,false>('c');
    // TODO 2.c call print_char with int implicitly and explicitly
    print_char<int>('c');
    print_char(77);
    // TODO 2.d call print_char with double without setting type.
    print_char(22.3);


    // TODO 3a. call get_max with "aaa" "b" and print
    // TODO 3.c rerun after specialization
    std::cout << get_max<string>("aaa","b") << std::endl;
    // what happens if we remove the word string? (get_max("aaa","b"))
    std::cout << get_max("aaa","b") << std::endl;

    pair_test();
}
