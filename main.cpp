#include <iostream>
#include <cstring>
using namespace std;

void change(int* arr, int size)
{

    for(int index = 0; index < size; ++index)
    {
        arr[index] = 20;
    }
}

void doubleValue(int& value)
{
    value = value + value;
}

void display(int* arr, int size)
{
    for(int index = 0; index < size; ++index)
    {
        cout << arr[index] << endl;
    }
}

// Driver Code
int main()
{
    int* test;
    int arr[] = {1, 2, 3, 4, 5};

    test = arr;

    display(test, 5);

    change(arr, 5);

    test = arr;

    display(test, 5);

    int testing = 5;

    cout << testing << endl;

    doubleValue(testing);

    cout << testing << endl;

    return 0;
}
