#ifndef CLASSES_H_
#define CLASSES_H_

#include <iostream>

class Item
{
    int data;
public:
    Item() : data(0)
    {}

    void SetData(int value)
    { 
        data = value;
    }

    int GetData() const
    {
        return data;
    }

    void PrintData() const
    {
        std::cout << data;
    }
};

// When this template is compiled
// the compiler make only syntax checking
// When you instantiate it with specific
// type then the true error checking is made
template<typename T>
class TemplateItem
{
    T data;
public:
    // T must have cctor
    // and default ctor
    TemplateItem() : data(T())
    {}

    // must have operator =
    // cctor
    void SetData(T val)
    {
        this->data = val;
    }

    // must have cctor
    T GetData() const
    {
        return this->data;
    }
    
    /*T GetDataWrong() const*/
    /*{*/
    /*for());*/
    /*return this->data;*/
    /*}*/

    // It compiles when
    // it is used in actual
    // code. But if you use
    // it with type which doesnt support
    // operator [] it will crash
    /*T GetDataAmbigous() const*/
    /*{*/
    /*T temp = this->data[0];*/
    /*return this->data;*/
    /*}*/

    // must have overloaded operator <<
    void PrintData()
    {
        std::cout << this->data;
    }
};


template<typename T1, typename T2>
struct TemplatePair
{
    // cctor
    // default ctor
    TemplatePair()
    : first(T1()),
      second(T2())
    {}

    //ctor
    TemplatePair(const T1& t1, const T2& t2)
    : first(t1),
      second(t2)
    {}
    
    const TemplatePair& operator = (const TemplatePair<T1, T2> t)
    {
        if(this != &t)
        {
            this->first = t.first;
            this->second  = t.second;
        }

        return *this;
    }
    // it is better to specialize the arguments
    // as const Template<T1, T2>& t
    // because it can appear a compiler issue
    // says that argument is not a template
    TemplatePair(const TemplatePair& t)
    : first(t.first),
      second(t.second)
    {}

    bool operator == (const TemplatePair<T1, T2> t) const
    {
        return this->first == t.first &&
               this->second == t.second;
    }

    void Print() const
    {
        std::cout << this->first
                  << std::endl
                  << this->second
                  << std::endl;

    }
    
    T1 first;
    T2 second;
};

// template class with non template arguments
// Only integral types can be non template arguments
// int, long, short, enum, char, unsigned
template<typename T, int SIZE>
class TemplateArray
{
public:
    TemplateArray()
    {
        // Init with default ctor
        for(int i = 0; i < SIZE; ++i)
        {
            arr[i] = T();
        }
    }

    T& operator[](int index)
    {
        if(index >= 0 && index < SIZE)
        {
            return arr[index];
        }
    }

    void Print() const
    {
        for(int i = 0; i < SIZE; ++i)
        {
            arr[i].Print();
        }

        std::cout << std::endl;
    }

private:
    T arr[SIZE];
};

// every argument can be default
//
template<typename T=int, int SIZE=100>
class DefaultTemplateArray
{
public:
    DefaultTemplateArray()
    {
    
        for(int i = 0; i < SIZE; ++i)
        {
            arr[i] = T();
        }
    }
private:
    T arr[SIZE];
};

#endif // CLASSES_H_
