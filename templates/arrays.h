#ifndef ARRAYS_H_
#define ARRAYS_H_


// Here ODT have to support:
// accessible default ctor
// operator +=
// cast operator double
// no need of cctor because the result is return
// as double
template<typename T>
double GetAverage(T array[], int size)
{
    T sum = T(); // with simple words: call default ctor

    for(int i = 0; i < size; ++i)
    {
        sum += array[i];
    }

    return double(sum) / size;
}

// Reference
// output will be in dest
template<typename T>
void RefAdd(T& dest, T src)
{
    dest += src;
}

// This cannot be used because
// the argument is const
// and the return type is not const
// It will be compiled but!!! test it
template<typename T>
T& GetTrival(const T& t)
{
    return t;
}

template<typename K, typename V>
void PrintPair(const K& key, const V& value)
{

    std::cout << "I'm PrintPair: \n";
    std::cout << "key: " << key
              << std::endl
              << "value: " << value
              << std::endl;
}

struct Pair
{
    unsigned age;
    std::string name;
};

class User
{
public:
    User(const std::string& name, double sal)
    : first_name(name),
      salary(sal)
      {}

private:
    std::string first_name;
    double salary;
    friend std::ostream& operator << (std::ostream& os,
                                      const User& usr);
};

std::ostream& operator << (std::ostream& os,
                           const User& usr)
{
    os << usr.first_name 
       << std::endl 
       << usr.salary
       << std::endl;

    return os;
}


void Show(int a)
{
    std::cout << a;
}

template<typename T>
void TemplateShow(T a)
{
    std::cout << a;
}

template<typename T>
void SizeOfElement()
{
    std::cout << "Im SizeOfElement<T>:";
    std::cout << sizeof(T)
              << std::endl;
}



template<class T>
void PrintNumbers(T array[], int array_size, T filter = T())
{
   for(int nIndex = 0; nIndex < array_size; ++nIndex)
   {
        // Print if not filtered
        if ( array[nIndex] != filter) 
        {
            std::cout << array[nIndex] << " ";
        }
   }
   std::cout << std::endl;
}



#endif // ARRAYS_H_
