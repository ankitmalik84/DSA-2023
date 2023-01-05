/*
    Dividend = Quotient * Divisor + Remainder

    Dividend / Divisor = Quotient
    Dividend % Divisor = Remainder

    Dividend = Quotient (new value)* Divisor + Remainder(old value)


    // HUm dekh rahe hai ki array ki even index pr maximum values hai aur odd


    Max = arr[n-1]+1;

    max_index = n-1;
    min_index = 0;

    index % 2 == 0           Arr[i] = (Arr[max_index]%Max)*Max + Arr[i]
    index % 2 !=0            Arr[i] = (Arr[min_index]%Max)*Max + Arr[i]


    // please dry run 1-2 times for better understanding......

*/
#include <iostream>
using namespace std;

void rearrange(long long int arr[], int n)
{
    int max_index = n - 1;
    int min_index = 0;
    int max = arr[n - 1];

    for (int i = 0; i < n; i++)
    {
        if (n % 2 == 0)
        {
            arr[i] = (arr[max_index] % max) * max + arr[i];
            max_index--;
        }
        else
        {
            arr[i] = (arr[min_index] % max) * max + arr[i];
            min_index--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] /= max;
    }
}

int main()
{
    int t;
    // testcase
    cin >> t;
    while (t--)
    {
        // size of array
        int n;
        cin >> n;

        long long int arr[n];

        // adding element in the array
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        rearrange(arr, n);
    }
    return 0;
}
