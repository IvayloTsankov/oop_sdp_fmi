#include <iostream>
#include <string>

void printInt(int a)
{
    std::cout << a << std::endl;
}

void printDouble(double a)
{
    std::cout << a << std::endl;
}


template<typename T>
void PrintData(const T& data)
{
    std::cerr << data << std::endl;
}


int main()
{
    printInt(10);
    printInt(20);
    printInt(20.20);
    printDouble(20.20);

    std::string name("Pesho");

    PrintData(name);
    PrintData(20);
    PrintData(20.20);
    PrintData('x');
    PrintData(40000000000);

    return 0;
}
