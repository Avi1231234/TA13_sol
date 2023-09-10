//
// Created by punims on 10/06/2021.
//

#ifndef TA12_GenericPair_H
#define TA12_GenericPair_H

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>


//TODO 4a. Write a templated class called GenericPair which can hold two
// members of the same type
template <class T> // Same as template <typename T>
class GenericPair
{
public:
    GenericPair(T first, T second): first(first), second(second){count++;}

    GenericPair(GenericPair<T> &other): GenericPair<T>(other.first, other.second){} // copy ctor
    GenericPair<T>& operator=(const GenericPair<T> &other);
   ~GenericPair<T>(){count--;} //dtor

   T get_first() const {return first;}
   T get_second() const {return second;}
   int get_count() const {return count;}

private:
    T first;
    T second;
    //TODO: 4b. Add a static counter which counts the “living” class
    // instances (increases in the constructor and decreases in the destructor)
    static int count;
};

template<class T>
int GenericPair<T>::count = 0;


//TODO: 4c. Add a basic constructor and rule of three methods to this class.
// What happens when we try and put the implementation in a .cpp file
// and the declaration in the header file?
template<class T> GenericPair<T>& GenericPair<T>::operator= (const GenericPair<T> &other)
{
    if(this == &other)
      {
        return *this;
      }
    first = other.first;
    second = other.second;
    return *this;
}



#endif //TA12_GenericPair_H
