// GFG
// Q13
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getPairsCount(int arr[], int n, int k)
    {
        // yaha hum map use karenge kyoki map ki time avg. complexity o(1) hoti hai brute force approach se bhi ho jayega ye but in O(n2) m
        unordered_map<int, int> m;
        int ans = 0;
        // linear loop chalayenge........
        for (int i = 0; i < n; i++)
        {

            int b = k - arr[i];
            // agar b hum mila ra hai toh usski frequency ko add karo
            if (m[b])
            {
                ans += m[b];
            }
            // varna frequency increment kar do
            m[arr[i]]++;
        }
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }

    return 0;
}
