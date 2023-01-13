// Q26
// no. 36
#include <bits/stdc++.h>
using namespace std;
// this is two pointerapproach
class Solution
{
public:
    int smallestSubWithSum(int a[], int n, int x)
    {
        // here we take mi variable to store length of min array------------->
        int mi = INT_MAX;
        int i = 0, j = 0;
        int s = 0;
        while (i <= j && j < n)
        {
            // jab s ki value chooti h x se tab hum element jodte rahenge
            while (s <= x && j < n)
            {
                s += a[j++];
            }
            // jab s>x hogi yani hmara sub array mil chuka bss use optimize karna hai------>
            while (s > x && i < j)
            {
                // yaha index store karenge i se bich ka diff hi length hogi-------------->
                mi = min(mi, j - i);
                s -= a[i];
                i++;
            }
        }
        return mi;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.smallestSubWithSum(a, n, x) << endl;
    }
    return 0;
}