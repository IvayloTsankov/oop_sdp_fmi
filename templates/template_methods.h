#ifndef TEMPLATE_METHODS_H_
#define TEMPLATE_METHODS_H_

class IntArray
{
public:
    // default ctor
    IntArray()
    {
        for(int i = 0; i < 10; ++i)
        {
            arr[i] = i;
        }
    }

    int operator [] (int index)
    {
        if(index > 0 && index < 10)
        {
            return this->arr[index];
        }
    }

    template<typename T>
    void Copy(T target_array[10])
    {
        for(int i = 0; i < 10; ++i)
        {
            target_array[i] = arr[i];
            // or more precisely
            // target_array[i] = static_cast<T>(arr[i]);
        }
    }

private:
    int arr[10];
};


template<typename T>
class Comparer
{
public:
    Comparer(const T& tdata = T())
    : data(tdata)
    {
    }

    template<typename C>
    bool IsEqual(const C& other_data)
    {
        return data == other_data;
    }

    template<typename K>
    operator K() const
    {
        return data;
        /*or more precisely */
        /*return static_cast<K>(data);*/
    }

    const T& Data() const
    {
        return data;
    }

private:
    T data;
};

#endif // TEMPLATE_METHODS_H_
