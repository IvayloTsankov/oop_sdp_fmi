#ifndef VECTOR_H_
#define VECTOR_H_

#include <climits>
#include <iostream> //for definition of NULL

#define INVALID_DATA INT_MIN

class Vector
{
public:
    Vector();
    Vector(unsigned size);
    Vector(const Vector& r_vector);
    Vector& operator = (const Vector& r_vector);
    ~Vector();

public:
    int size() const { return this->size_; }
    int operator [] (int index);
    
    bool empty() const;

    void clean();
    void push_back(int val);
    int pop_back();

private:
    void resize();
    void shrink();
    void copy(int* src_data, int* dest_data, unsigned size);

private:
    unsigned capacity_;
    unsigned size_;
    int* data_;
};

#endif // VECTOR_H_

