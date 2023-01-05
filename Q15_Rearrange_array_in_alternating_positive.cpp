/* C++ program to rearrange
positive and negative integers
in alternate fashion while keeping
the order of positive and negative numbers. */
#include <assert.h>
#include <iostream>
using namespace std;

// Utility function to right rotate all elements between
// [wrongIndex, cur]
// yaha hum right rotate karege jis se element shift ho jaye aur negative element apni jagah pr aa jaye
void rightrotate(int arr[], int n, int wrongIndex, int cur)
{
    char tmp = arr[cur];
    for (int i = cur; i > wrongIndex; i--)
        arr[i] = arr[i - 1];
    arr[wrongIndex] = tmp;
}

void rearrange(int arr[], int n)
{
    // starting m hum wrong index -1 maan k chalenge
    int wrongIndex = -1;

    for (int index = 0; index < n; index++)
    {
        if (wrongIndex >= 0)
        {
            // find the item which must be moved into the
            // out-of-place entry if out-of-place entry is
            // positive and current entry is negative OR if
            // out-of-place entry is negative and current
            // entry is negative then right rotate
            //
            // [...-3, -4, -5, 6...] --> [...6, -3, -4,
            // -5...]
            //	 ^						 ^
            //	 |						 |
            //	 wrongIndex	 -->	 wrongIndex
            //
            if (((arr[index] >= 0) && (arr[wrongIndex] < 0)) || ((arr[index] < 0) && (arr[wrongIndex] >= 0)))
            {
                rightrotate(arr, n, wrongIndex, index);

                // the new wrong-index entry is now 2 steps
                // ahead
                // agar index aur wrong index k bich ka diff 2 ya 2 se jyada hai toh hum usse increment kardenge phir hum utne hi element ka rightrotate karenge
                if (index - wrongIndex >= 2)
                    wrongIndex = wrongIndex + 2;
                // agar unke biche ka diff 2 se kaam hai toh yani element shi order main hain
                else
                    wrongIndex = -1;
            }
        }

        // if no entry has been flagged wrong-index
        if (wrongIndex == -1)
        {
            // check if current entry is wrong-index
            if (((arr[index] >= 0) && (!(index & 0x01))) || ((arr[index] < 0) && (index & 0x01)))
            {
                wrongIndex = index;
            }
        }
    }
}

// A utility function to print an array 'arr[]' of size 'n'
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{

    int arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArray(arr, n);

    rearrange(arr, n);

    cout << "Rearranged array is \n";
    printArray(arr, n);

    return 0;
}
