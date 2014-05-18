#ifndef USER_DEFINED_TYPES_H_
#define USER_DEFINED_TYPES_H_

class Rational
{
public:
    Rational operator * (const Rational& r)
    {
        Rational result;
        result.chis = this->chis * r.chis;
        result.znam = this->znam * r.znam;

        return result;
    }
   
    Rational operator * (int r)
    {
        Rational result;
        result.chis = this->chis * r;
        result.znam = this->znam;

        return result;
    }


private:
    int chis;
    int znam;
};



class Neshto
{
public:
    Neshto()
    : i(0)
    {
    }

    Neshto(int p)
    : i(p)
    {
    }

    Neshto operator * (const Neshto& n)const 
    {
        Neshto temp;
        temp.i = this->i * n.i;
        return temp;
    }

    friend std::ostream& operator << (std::ostream& os, const Neshto& n);

private:
    int i;
};


std::ostream& operator << (std::ostream& os, const Neshto& n)
{
    os << n.i;
    return os;
}

#endif // USER_DEFINED_TYPES_H_

