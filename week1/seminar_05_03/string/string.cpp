#include "string.h"
#include <cstring> //strlen(), strcpy()


void String::free(char* target)
{
	if(target != NULL)
	{
		delete [] target;
		target = NULL;
	}
}

void String::copy(char* dest, const char* src, size_t size)
{
	dest = new char[size];
	strcpy(dest, src, size);
}

String::String()
: data_(NULL),
  size_(0)
{
}

// user reference to prevent String str(NULL);
String::String(const char& val)
: data_(NULL),
  size_(0)
{
	size_t len = strlen(val) + 1;
	this->size_ = len;
	
	copy(this->data_, val, this->size_);
}

// give a promise to compiler that I'll not
// alter str
String::String(const String& str)
: data_(NULL),
  size_(str.size_)
{
	copy(data_, str.data_, this->size_);
}

String& String::operator = (const String& str)
{
	// prevent self copy
	if(this != &str)
	{
		this->size_ = str.size_;
		
		free(this->data_); // first free the old data
		copy(this->data_, str.data_, this->size_); // make a copy of str.data_ 
	}

	return *this;
}

String::~String()
{
	// release the allocated data
	free(this->data_);
}

// this method will not alter the object
// it should be declared as const
// then it can be called from const object
// Example:
// const String str;
// str.empty(); it's ok becaus empty is const method
// str.clean(); it's not ok because clean is not const method
// on const object you can use only const methods
bool String::empty() const
{
	return (this->size_ == 0);
}

bool String::clean()
{
	free(data_);
	this->size_ = 0;
}

// this method return a const char* pointer
// which means that you cannot alter the data
// which is pointed from const pointer
// protect the data
// this method is const and this means that it
// can be used from const object
const char* String::c_str() const
{
	return this->data_;
}
