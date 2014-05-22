#include <iostream>
using namespace std;


void sumArrays(int** first, int** second, int** result, int n)
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            result[i][j] = first[i][j] + second[i][j];
        }
    }
}

int mainDiagonalProduct(int** array, int n)
{
    if(array == NULL || n <= 0)
    {
        return 0;
    }

    int product = 1;
    for(int i = 0; i < n; ++i)
    {
        product *= array[i][i];
    }

    return product;
}

void fillArray(int** arr, int n)
{
    if(arr == NULL || n <= 0)
    {
        return;
    }


    cout << "Insert " << n*n << " numbers: ";
    int number;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> number;
            arr[i][j] = number;
        }
    }
}

int main()
{
    // user input for n
    cout << "Insert N: ";
    int n;
    cin >> n;
    
    if(n <= 0)
    {
        return -1;
    }


    int** x = new int*[n];
    int** y = new int*[n];
    int** z = new int*[n];
    for(int i = 0; i < n; ++i)
    {
        x[i] = new int[n];
        y[i] = new int[n];
        z[i] = new int[n];
    }

    fillArray(x, n);
    fillArray(y, n);

    sumArrays(x, y, z, n);

    int diag_product = mainDiagonalProduct(z, n);
    cout << "Main diagonal product is: " << diag_product << endl;

    for(int i = 0; i < n; ++i)
    {
        delete [] x[i];
        delete [] y[i];
        delete [] z[i];
    }

    delete [] x;
    delete [] y;
    delete [] z;

    return 0;
}
