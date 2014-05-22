#include <iostream>
#include <cmath>
using namespace std;

double FarenheitToCelsius(double farenheit)
{
    double result = 0;
    result = (5 * (farenheit -32)) / 9;

    return result;
}

double CelsiusToFarenheit(double celsius)
{
    double result = 0;
    result = ((5 * 32) + (9*celsius)) / 5;

    return result;
}

int main()
{
    // tests 
    cout << "32F->C: " << FarenheitToCelsius(32) << endl;
    cout << "212F->C: " << FarenheitToCelsius(212) << endl;
    cout << "100C->F: " << CelsiusToFarenheit(100) << endl;

    return 0;
}
