#include <iostream>
#include <cmath>

using namespace std;

double FarenheitToCelsius(double farenheit)
{
    double result;
    result = (5 * (farenheit -32)) / 9;

    return result;
}

double CelsiusToFarenheit(double celsius)
{
    double result;
    result = ((5 * 32) + (9*celsius)) / 5;

    return result;
}

int main()
{
    // tests 
    cout << "32F->C: " << FarenheitToCelsius(32) << endl;
    cout << "212F->C: " << FarenheitToCelsius(212) << endl;
    cout << "100C->F: " << CelsiusToFarenheit(100) << endl;


    int choise;
    double user_input;
    double result;
    cout << "1. Celsius->Farenheit" << endl
         << "2. Farenheit->Celsius" << endl
         << "Input: ";
    cin >> choise;
    if(choise == 1)
    {
        cout << "Enter Celsius: ";
        cin >> user_input;
        result = CelsiusToFarenheit(user_input);
        cout << "Celsuis(" << user_input << ")->Farenheit: " << result;
    }
    else if(choise == 2)
    {
        cout << "Enter Farenheit: ";
        cin >> user_input;
        result = FarenheitToCelsius(user_input);
        cout << "Farenheit(" << user_input << ")->Celsius: " << result;
    }
    else
    {
        cout << "Bad Input!";
    }
    cout << endl;
    

    system("pause");
    return 0;
}
