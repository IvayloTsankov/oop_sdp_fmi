#ifndef BASIC_H_
#define BASIC_H_

#include <iostream>

/*
Templates can be two types:
    1. Function Templates
    2. Class Templates


    1. Functions templates:
        Abstract:
            Use function templates when we want to write
            an algorithm without defining the type of the
            arguments. The algorithm is generic. It can
            handle many types of data

        Syntax:
            template<typename T>
            return_value function_name(args) { // body }

*/

// Example 1:
// Here for UDT (user defined types)
// you have to define operator *
template<typename T>
void PrintPower(const T& data)
{
    std::cout << data * data << std::endl;
}

// Example 2:
template <typename T>
T Double(T data)
{
    return data * 2;
}


/*template<typename T>*/
/*T add(T elem1, T elem2)*/
/*{*/
/*return elem1 + elem2;*/
/*}*/

// The compiler will check only
// for basic syntax rules.
// If you want use this template
// with a UDT it have to have
// default constructor for T result creation
// and operator + defined.
// T have to support copy and assigment (cctor and operator =)
// because return statement will copy the result object
template<typename T>
T add(T elem1, T elem2)
{
    T result;
    result = elem1 + elem2;

    return result;
}

// for UDT have to define operato =
template<typename T>
void swap(T& elem1, T& elem2)
{
    T temp = elem1;
    elem1 = elem2;
    elem2 = temp;
}







#endif // BASIC_H_
