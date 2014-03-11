#ifndef STRING_H_
#define STRING_H_

class String
{
public:
    String();
    String(const char* val);
    ~String();
    
    //assignment and copy
    String& operator = (const String& str);
    String(const String& rstr);

public:
    bool empty() const;
    void clean();
    const char* c_str() const;

    void append(String& str);
    void append(char* str);

    const char* find(char* val); //return pointer to first occurence
   
    String operator + (const String& str);
    String& operator += (const String& str);
    char& operator [] (int); //unsigned is better
    const char& operator p[] (int);
    
    String substr(unsigned pos, unsigned size);

private:
    char* data_;
    unsigned size_;
};

#endif // STRING_H_
