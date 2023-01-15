// Q28
//  no.38
//  C++ program to find minimum swaps required
//  to club all elements less than or equals
//  to k together
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSwap(int arr[], int n, int k)
    {
        // Complet the function
        // here we use window method first we make a window of size of fav. conditions
        int fav = 0, nonfav = 0;
        // count no. of fav. elements
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= k)
                fav++;
        }
        // here in window count nonfav elements
        for (int j = 0; j < fav; j++)
        {
            if (arr[j] > k)
                nonfav++;
        }
        int l = 0, r = fav - 1, result = INT_MAX;
        // reult store min no. of swap req
        while (r < n)
        {
            result = min(result, nonfav);
            r++;
            // movw window forward direction include r+1 elemnt and exclude l-1 element
            // if new element in nonfav then nonfav++
            if (r < n && arr[r] > k)
            {
                nonfav++;
            }
            // if exclude element is nonfav element then nonfav--
            if (l < n && arr[l] > k)
                nonfav--;
            l++;
        }
        // return result when result var hav any value otherwise 0----------------->
        return (result == INT_MAX ? 0 : result);
    }
};

int main()
{

    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cin >> k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
    return 0;
}
