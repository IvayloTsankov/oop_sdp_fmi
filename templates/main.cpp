#include <iostream>
#include "basic.h"
#include "user_types.h"
#include "arrays.h"
#include "template_classes.h"
#include "template_methods.h"


#include <vector>

int main()
{
    //basic
    std::cout << Double(Double(2)) << std::endl;
    std::cout << Double(3.14) << std::endl;
    std::cout << Double(2.222222) << std::endl;
    
    PrintPower(10);
    PrintPower(3.14);
    PrintPower(2.222);
    
    Neshto drugo(20);
    PrintPower(drugo);
    std::cout << add(5, 10) << std::endl;
    
    int a = 10, b = 20;
    std::cout << "a: " << a << std::endl << "b: " << b << std::endl;
    std::cout << "swap..." << std::endl;

    swap(a, b);
    std::cout << "a: " << a << std::endl << "b: " << b << std::endl;

    //arrays
    int p();
    std::cout << "p: " << p << std::endl;
    int q();
    std::cout << "q: " << q << std::endl;
    std::cout << "int(): " << int() << std::endl;
    
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    std::cout << "GET AVERAGE: "  << GetAverage<int>(arr, 10) << std::endl;

    float f_arr[5] = {1.1,2.2,3.3,4.4,5.5};
    std::cout << "int args: " << GetAverage<int>(arr, 10) << std::endl;
    std::cout << "float args: " << GetAverage<float>(&f_arr[0], 5) << std::endl;

    std::cout << "float args with int function: " << GetAverage<int>(arr, 5);

    int t = 10;
    std::cout << "t: " << t << std::endl;
    RefAdd(t, 5);
    std::cout << "t: " << t << std::endl;
   
    // This will not be compiled
    // Because we take a const & as
    // argument and the return type
    // is not const When break
    // the constness of the argument
    //int immutable_number = 10;
    //++GetTrival(immutable_number);

    Pair pesho = {20, "Pesho"};
    PrintPair(pesho.age, pesho.name);

    std::string pi_key = "PI";
    double pi_value = 3.14;

    PrintPair(pi_key, pi_value);
    PrintPair("Pesho", "Goshov");

    // print gosho
    User gosho("Gosho", 2000);
    int user_id=25;
    PrintPair(user_id, gosho);
    
    // Note:
    // When we use a template function
    // with similar parameters (e.g. short, int, long)
    // which can be converted to one another
    // the template engine will not reuse the created
    // functions and implicitly convert the arguments
    // Example:
    //      short a = 10;
    //      int b = 200000000;
    //      double c = 2.15;
    //      long d = 40000000000; 40 bilions
    //
    //      PrintPair(a, b); same as PrintPair<short, int> 
    //      PrintPair(b, a); --|-- PrintPair<int, short>
    //      PrintPair(a, d); --|-- PrintPair<short, long>
    //      PrintPair(d, c); --|-- PrintPair<long, double>
    
    Show(120);
    Show('B');
    Show(21.5);

    TemplateShow(120); // will produce TemplateShow<int> 
    TemplateShow('X'); // will produce TemplateShow<char>
    TemplateShow(21.5); // will produce TemplateShow<double>

    // the compiler will not make an analisys
    // of the parameter because the function
    // is called explicitly with type double
    // and the argument will be taken as double
    // although it can be put in int
    TemplateShow<double>(1234); 
    

    // SizeOfElement(); // cannot be called
    SizeOfElement<float>();
    SizeOfElement<int>();
    SizeOfElement<short>();
    SizeOfElement<User>();
    
    int int_arr[10] = {1,2,3,0,4,0,2,0,9,10};
    PrintNumbers(int_arr, 10); // this will skip 0-s
    PrintNumbers(int_arr, 10, 2); // this will skip 2-s

    // TEMPLATE CLASSES USAGE
    Item i1;
    i1.SetData(120);
    i1.PrintData();
    
    TemplateItem<double> t1;
    t1.SetData(3.14);
    t1.PrintData();

    TemplateItem<char> t2;
    t2.SetData('X');
    char big_x = t2.GetData();
    std::cout << big_x << std::endl;
    t2.PrintData();

    //t1 = t2; //this will cause error
    // because t1 is instace of the template
    // class with double and t2 is instance with char

    TemplatePair<int, std::string> t_pair1;
    TemplatePair<int, int> salary;
    salary.first = 200; // leva
    salary.second = 30; // coins
    std::cout << "salary: ";
    salary.Print();
    TemplatePair<int, int> int_pair1(10, 20);
    TemplatePair<int, int> int_pair2(int_pair1);
    int_pair1.Print();
    int_pair2.Print();
    // it will cause an error 
    //TemplatePair<int, float> int_float_pair(int_pair2);


    // Exercise: Implement
    // 1. operator =
    // 2. operator <
    // 3. operator >
    // 4. swap method
    // 5. modify the constructor with default arguments
    int pp;
    int qq = int();
    std::cout << "pp: " << pp << std::endl;
    std::cout << "qq: " << qq << std::endl;

    // Template of template
   TemplateArray<TemplatePair<int, int>, 10> t_arr_t_pair;
   t_arr_t_pair[0] = TemplatePair<int, int>(5, 5); 
    t_arr_t_pair.Print();

    typedef TemplatePair<int, int> Salary;
    TemplatePair<std::string, Salary> peshko;


    std::vector<int> int_vector;
    std::vector<TemplatePair<int, int> > int_pair_vector;

    // this will make a int array of 100 elements
    DefaultTemplateArray<> default_arr_int;

    DefaultTemplateArray<double> def_size_d_arr;


// TEMPLATE METHODS
    
    IntArray int_arr_obj;
    float float_arr[11];
    int_arr_obj.Copy(float_arr);
    // or more explicitely int_arr_obj.Copy<float>(float_arr);
    
    std::cout << "Print int_arr_obj: " << std::endl;
    for(int i = 0; i < 10; ++i)
    {
        std::cout << int_arr_obj[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Print float_arr: " << std::endl;
    for(int i = 0; i < 10; ++i)
    {
        std::cout << int_arr_obj[i] << " ";
    }
    std::cout << std::endl;

    Comparer<int> c_int(10);
    float c_float = 10;

    std::cout << std::boolalpha << c_int.IsEqual(c_float)
              << std::endl;
    
    Comparer<int> cc_int(40);
    float cc_float;
    double cc_double;

    cc_float = cc_int;
    cc_double = cc_int;
    // which will invoke
    // Comparer<int>::operator<float> float();
    // Comparer<int>::operator<double> double();

    std::cout << "cc_int: " << cc_int.Data() << "\n"
              << "cc_float: " << cc_float << "\n"
              << "cc_double: " << cc_double << "\n";


    return 0;
}



