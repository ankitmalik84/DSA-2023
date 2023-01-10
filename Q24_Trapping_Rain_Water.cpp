// Q24
// no 34
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    // Function to find the trapped water between the blocks.
public:
    long long trappingWater(int arr[], int n)
    {
        long long res = 0;
        int lmax[n], rmax[n];
        lmax[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (lmax[i - 1] < arr[i])
            {
                lmax[i] = arr[i];
            }
            else
                lmax[i] = lmax[i - 1];
        }
        rmax[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            if (rmax[i + 1] < arr[i])
            {
                rmax[i] = arr[i];
            }
            else
                rmax[i] = rmax[i + 1];
        }
        for (int i = 1; i < n - 1; i++)
        {
            if (lmax[i] <= rmax[i])
                res = res + (lmax[i] - arr[i]);
            else
                res = res + (rmax[i] - arr[i]);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    // testcases
    cin >> t;

    while (t--)
    {
        int n;

        // size of array
        cin >> n;

        int a[n];

        // adding elements to the array
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        // calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
    }

    return 0;
}