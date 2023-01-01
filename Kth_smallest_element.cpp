//{ Driver Code Starts
// Initial function template for C++

#include <iostream>
using namespace std;

class Solution
{
public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    void quick_sort(int a[], int b, int e)
    {
        int l, k, r, t;
        l = b;
        r = e;
        k = b;
        if (b >= e)
            return;
        while (1)
        {
            while (a[r] > a[k] && k != r)
                r = r - 1;
            if (k == r)
                break;
            if (a[k] > a[r])
            {
                t = a[k];
                a[k] = a[r];
                a[r] = t;
                k = r;
            }

            while (a[l] < a[k] && k != l)
                l = l + 1;
            if (l == k)
                break;
            if (a[k] < a[l])
            {
                t = a[k];
                a[k] = a[l];
                a[l] = t;
                k = l;
            }
        }
        quick_sort(a, b, k - 1);
        quick_sort(a, k + 1, e);
    }

    int kthSmallest(int arr[], int l, int r, int k)
    {
        // code here
        quick_sort(arr, 0, r);
        return arr[k - 1];
    }
};

//{ Driver Code Starts.

int main()
{
    int test_case;
    cin >> test_case;
    while (test_case--)
    {
        int n;
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        int k;
        cin >> k;
        Solution ob;
        cout << ob.kthSmallest(a, 0, n - 1, k) << endl;
    }
    return 0;
}
