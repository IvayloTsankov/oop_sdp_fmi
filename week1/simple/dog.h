#ifndef DOG_H_
#define DOG_H_

enum Fur { SHORT=0, MIDDLE, LONG };

class Dog
{
public:
    Dog(Fur f, int legs)
    {
        this->legs = legs;

        if(int(f) < 0 || int(f) > 3)
        {
            this->dog_fur = f;
        }
    }

    void print_fur()
    {
        switch(int(fur))
        {
            case 0:
                std::cout << "Short\n";
                break;
            case 1:
                std::cout << "Middle\n";
                break;
            case 2:
                std::cout << "Long\n";
                break;
            default:
                //this can happen ... WHY??
        }
    }

private:
    int legs;
    Fur dog_fur;
};

#endif // DOG_H_
