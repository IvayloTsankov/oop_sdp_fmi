#include "vector.h"

Vector::Vector()
: capacity_(1),
  size_(0),
  data_(NULL)
{
    this->data_ = new int[this->capacity_];
}

Vector::Vector(unsigned size)
: capacity_(1),
  size_(0),
  data_(NULL)
{
    if(size > this->capacity_)
    {
        this->capacity_ = size;
    }

    this->data_ = new int[this->capacity_];
}

Vector::Vector(const Vector& r_vector)
: data_(NULL),
  capacity_(r_vector.capacity_),
  size_(r_vector.size_)
{
    this->data_ = new int[capacity_];

    copy(r_vector.data_,this->data_, r_vector.size_);
}

Vector& Vector::operator = (const Vector& r_vector)
{
    if(this != &r_vector)
    {
        if(this->data_ != NULL)
        {
            delete [] this->data_;
            this->data_ = NULL;
        }
        
        this->capacity_ = r_vector.capacity_;
        this->size_ = r_vector.size_;

        this->data_ = new int[this->capacity_];

        copy(r_vector.data_, this->data_, r_vector.size_);
    }

    return *this;
}

Vector::~Vector()
{
    if(this->data_ != NULL)
    {
        delete [] this->data_;
        this->data_ = NULL;
    }
}

void Vector::copy(int* src_data, int* dest_data, unsigned size)
{
    for(unsigned i = 0; i < size; ++i)
    {
        dest_data[i] = src_data[i];
    }
}

void Vector::resize()
{
    int* temp_arr = this->data_;
    this->data_ = NULL;

    this->capacity_ *= 2;
    this->data_ = new int[this->capacity_];

    copy(temp_arr, this->data_, this->size_);

    delete [] temp_arr;
}

void Vector::shrink()
{
    int* temp_arr = this->data_;
    this->data_ = NULL;

    this->capacity_ /= 2;
    this->data_ = new int[this->capacity_];

    copy(temp_arr, this->data_, this->size_);
}

int Vector::operator [] (int size)
{
    if(size < 0 || size > this->size_)
    {
        return INVALID_DATA;
    }

    return this->data_[size];
}

bool inline Vector::empty() const
{
    return this->size_ == 0;
}

void Vector::push_back(int val)
{
    if(this->size_ == this->capacity_)
    {
        resize();
    }

    this->data_[size_] = val; // or this->data_[size_++] = val;
    ++size_;
}

int Vector::pop_back()
{
    if(this->empty())
    {
        return INVALID_DATA;
    }

    // the actual size is 25 percent of total capacity
    // memory need to be shrinked
    if(this->capacity_ == 4*size_)
    {
        shrink();
    }

    --size_; 

    return this->data_[size_]; // or return this->data[--size_];
}

void inline Vector::clean()
{
    this->size_ = 0;
}
