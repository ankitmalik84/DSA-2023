// Q19
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // arr[] : the input array
    // N : size of the array arr[]

    // Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
        // array main ek hi element hai toh hum 1 return kar denge
        if (n == 1)
        {
            return 1;
        }
        int count = 1;
        int maxc = 1;
        sort(arr, arr + n);
        for (int i = 1; i < n; i++)
        {
            // agar last element and current element same hai toh hum count increment kar denge
            if (arr[i] == (arr[i - 1] + 1))
            {
                count++;
                maxc = max(count, maxc);
            }
            // agar koi do element same aate hai toh hum continue kar denge
            else if (arr[i - 1] == arr[i])
                continue;
            // agar koi bhi disturbance aata hai series m toh hum count ko 1 pr set kar denge
            else
            {
                count = 1;
            }
        }
        // yaha hum maximum number of count return kar denge...........
        return maxc;
    }
};

int main()
{
    int t, n, i, a[100001];
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.findLongestConseqSubseq(a, n) << endl;
    }
    return 0;
}
