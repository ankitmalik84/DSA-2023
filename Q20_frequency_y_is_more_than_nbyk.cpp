#include <bits/stdc++.h>
using namespace std;

// Approach 1 by me------------>
void morethanNbyK(int arr[], int n, int k)
{
    int x = n / k;
    sort(arr, arr + n);
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] == arr[i])
        {
            count++;
        }
        // agar count m repetition x se jayda hai toh hum value print kara denge
        if (count > x)
        {
            cout << arr[i] << " ";
            count = 1;
        }
    }
}

// Approach 2 by GFG----------->
//  void morethanNbyK(int arr[], int n, int k)
//  {
//      int x = n / k;

//     // unordered_map initialization
//     unordered_map<int, int> freq;

//     for (int i = 0; i < n; i++) {
//         freq[arr[i]]++;
//     }

//     // Traversing the map
//     for (auto i : freq) {

//         // Checking if value of a key-value pair
//         // is greater than x (where x=n/k)
//         if (i.second > x) {

//             // Print the key of whose value
//             // is greater than x
//             cout << i.first << endl;
//         }
//     }
// }

int main()
{
    int arr[] = {1, 1, 2, 2, 3, 5, 3, 4, 2, 2, 3, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    morethanNbyK(arr, n, k);

    return 0;
}