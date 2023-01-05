// GFG
// Q11
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    // here is the function just like merge sort only silly modification
    long long merge(long long arr[], long long left, long long mid, long long right)
    {
        int i, j, k;
        long long inversion_count = 0;
        i = left;
        j = mid;
        k = left;
        long long temp[right];
        while ((i <= mid - 1) && (j <= right))
        {
            if (arr[i] <= arr[j])
            {
                temp[k++] = arr[i++];
            }
            else
            {
                temp[k++] = arr[j++];
                // here we count the inversion because all remainig element in array is all inversions
                inversion_count += (mid - i);
            }
        }
        while (i <= mid - 1)
            temp[k++] = arr[i++];
        while (j <= right)
            temp[k++] = arr[j++];
        for (i = left; i <= right; i++)
            arr[i] = temp[i];
        return inversion_count;
    }

    long long merge_sort(long long arr[], long long left, long long right)
    {
        long long mid, inversion_count = 0;
        if (right > left)
        {
            mid = (right + left) / 2;
            inversion_count = merge_sort(arr, left, mid);
            inversion_count += merge_sort(arr, mid + 1, right);
            inversion_count += merge(arr, left, mid + 1, right);
        }
        return inversion_count;
    }
    long long int inversionCount(long long arr[], long long n)
    {

        return merge_sort(arr, 0, n - 1);
    }
};

int main()
{

    long long T;
    cin >> T;

    while (T--)
    {
        long long N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}
