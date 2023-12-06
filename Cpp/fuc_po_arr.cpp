#include <iostream>
using namespace std;
int fun(const int *arr, int size)
{
    int sum = *arr;
    for (int i = 1; i < sum; i++)
    {
        sum = sum + *(arr + 1);
    }
    return sum;
}

int main()
{
    const int SIZE = 5;
    int number[SIZE] = {1,2,3,4,50};
    cout<<fun(number,SIZE);
     return 0;
}
