// Q18
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to find maximum product subarray
    long long maxProduct(vector<int> arr, int n)
    {
        long long int maxp = INT_MIN;
        long long int prod = 1;
        for (int i = 0; i < n; i++)
        {
            prod = prod * arr[i];
            maxp = max(maxp, prod);
            // agar bich m zero aati hai toh hum prod ko reset kar k 1 pr set kar denge but maxProd vaise hi rahega
            if (prod == 0)
            {
                prod = 1;
            }
        }
        prod = 1;
        // yaha hum last se check karenge agar last se multilipcation ma aata hai toh usse max pr set kar denge
        for (int i = n - 1; i >= 0; i--)
        {
            prod = prod * arr[i];
            maxp = max(maxp, prod);
            if (prod == 0)
            {
                prod = 1;
            }
        }
        return maxp;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}