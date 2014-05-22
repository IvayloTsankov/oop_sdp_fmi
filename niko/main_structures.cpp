#include <iostream>
#include <string>
using namespace std;


struct Hospital
{
    void PrintInfo()
    {
        cout << endl
             << "lastname: " << last_name_ << endl
             << "diagnose: " << diagnose_ << endl
             << "price: " << price_ << endl
             << "period: " << period_ << endl;
    }

    string last_name_;
    string diagnose_;
    double price_;
    unsigned period_;
};


bool CreateHospital(Hospital& user)
{
    string lastname;
    string diagnose;
    double price;
    unsigned period;

    cout << "Enter: lastname" << endl;
    cin >> lastname;
    cout << "Enter: dianose" << endl;
    cin >> diagnose;
    cout << "Enter: price" << endl;
    cin >> price;
    cout << "Enter: period" << endl;
    cin >> period;

    user.last_name_ = lastname;
    user.diagnose_ = diagnose;
    user.price_ = price;
    user.period_ = period;
}


void swap(Hospital* first, Hospital* second)
{
    if(first == NULL || second == NULL)
    {
        return;
    }

    Hospital temp;
    temp.last_name_ = first->last_name_;
    temp.diagnose_  = first->diagnose_;
    temp.price_     = first->price_;
    temp.period_    = first->period_;

    first->last_name_ = second->last_name_;
    first->diagnose_ = second->diagnose_;
    first->price_ = second->price_;
    first->period_ = second->period_;

    second->last_name_ = temp.last_name_;
    second->diagnose_ = temp.diagnose_;
    second->price_ = temp.price_;
    second->period_ = temp.period_;
}


void SortByLastName(Hospital* array, int size)
{
    if(size < 0)
    {
        return;
    }

    for(int i = 0; i < size - 1; ++i)
    {
        for(int j = i+1; j < size; ++j)
        {
            if(array[i].last_name_ < array[j].last_name_)
            {
                swap(array[i], array[j]);
            }
        }
    }
}

Hospital* FindByDiagnose(Hospital* array, int size,
                         const string& diagnose)
{
    for(int i = 0; i < size; ++i)
    {
        if(array[i].diagnose_ == diagnose)
        {
            return &array[i];
        }
    }

    // user is not found
    return NULL;
}


Hospital* FindByLastName(Hospital* array, int size,
                         const string& lastname)
{
    for(int i = 0; i < size; ++i)
    {
        if(array[i].last_name_ == lastname)
        {
            return &array[i];
        }
    }

    return NULL;
}

Hospital* FindByMostExpensivePrice(Hospital* array, int size)
{
    if(array == NULL)
    {
        return NULL;
    }

    Hospital* user = &array[0];
    for(int i = 1; i < size - 1; ++i)
    {
        if(array[i].price_ > user->price_)
        {
            user = &array[i];
        }
    }

    return user;
}

Hospital* FindByLongestPeriod(Hospital* array, int size)
{
    if(array == NULL)
    {
        return NULL;
    }

    Hospital* user = &array[0];
    for(int i = 1; i < size - 1; ++i)
    {
        if(array[i].period_ > user->period_)
        {
            user = &array[i];
        }
    }

    return user;
}


Hospital* FindByShortestPeriod(Hospital* array, int size)
{
    if(array == NULL)
    {
        return NULL;
    }

    Hospital* user = &array[0];
    for(int i = 1; i < size - 1; ++i)
    {
        if(array[i].period_ > 0 && array[i].period_ < user->period_)
        {
            user = &array[i];
        }
    }

    return user;
}

void PrintAll(Hospital* arr, int size)
{
    for(int i = 0; i < size; ++i)
    {
        arr[i].PrintInfo();
    }
}


void PrintByDiagnose(Hospital* arr, int size)
{
    if(arr == NULL || size < 0)
    {
        return;
    }
    
    // sort by diagnose
    for(int i = 0; i < size; ++i)
    {
        for(int j = i+1; j < size - 1; ++j)
        {
            if(arr[i].diagnose_ < arr[j].diagnose_)
            {
                swap(arr[i], arr[j]);
            }
        }
    }

    PrintAll(arr, size);
}


void PrintMenu()
{
    cout << "Enter:" << endl
         << "1. Insert Hospital structure" << endl
         << "2. Sort by lastname" << endl
         << "3. Find and Print info by diagnose" << endl
         << "4. Find and Print info by lastname" << endl
         << "5. Find and Print info by the most expensive treatment" << endl
         << "6. Find and Print info by the longest peroid of treatment" << endl
         << "7. Find and Print info by the shortest peroid of treatment" << endl
         << "8. Find and Print info by different diagnoses" << endl
         << "9. Exit" << endl;
}

int main()
{
    Hospital* array = new Hospital[100];
    int counter = 0;

    bool exit = false;
    while(!exit)
    {
        PrintMenu();
        cout << "Enter choise [1, 9]: ";
        int choice;
        cin >> choice;
        if(!cin)
        {
            return -1;
        }

        cout << endl;

        switch(choice)
        {
        case 1:
        {
            CreateHospital(array[counter]); 
            counter++;
            break;
        }
        case 2:
        {
            SortByLastName(array, 100);         
            break;
        }
        case 3:
        {
            cout << "Enter diagnose: ";
            string diagnose;
            cin >> diagnose;
            Hospital* user = FindByDiagnose(array, 100, diagnose);
            if(user != NULL)
            {
                user->PrintInfo();
            }
            else
            {
                cout << "Can't find the user" << endl;
            }
            break;
        }
        case 4:
        {
            cout << "Enter lastname: ";
            string lastname;
            cin >> lastname;
            Hospital* user = FindByLastName(array, 100, lastname);
            if(user != NULL)
            {
                user->PrintInfo();
            }
            else
            {
                cout << "Can't find the user" << endl;
            }
            break;
        }
        case 5:
        {
            cout << "User with most expensive treatment: ";
            Hospital* user = FindByMostExpensivePrice(array, 100);
            if(user != NULL)
            {
                user->PrintInfo();
            }
            else
            {
                cout << "Can't find the user" << endl;
            }
            break;
        }
        case 6:
        {
            cout << "User with longest period: ";
            Hospital* user = FindByLongestPeriod(array, 100);
            if(user != NULL)
            {
                user->PrintInfo();
            }
            else
            {
                cout << "Can't find the user" << endl;
            }
            
            break;
        }
        case 7:
        {
            cout << "User with shortest period: ";
            Hospital* user = FindByShortestPeriod(array, 100);
            if(user != NULL)
            {
                user->PrintInfo();
            }
            else
            {
                cout << "Can't find the user" << endl;
            }
            
            break;
        }
        case 8:
        {
            PrintByDiagnose(array, counter);
            break;
        }
        case 9:
        {
            delete [] array;
            exit = true;
            break;
        }
        case 10:
        {
            PrintAll(array, 100);
            break;
        }
        default:
            break;
        }
    }
    return 0;
}
