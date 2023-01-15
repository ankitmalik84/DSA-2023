// Q30
//  no.40
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int find_median(vector<int> v)
    {
        int size = v.size();
        sort(v.begin(), v.end());
        int mid = (size - 1) / 2;
        int result;
        if (size % 2 != 0)
        {
            result = v[mid];
        }
        else
        {
            result = (v[mid] + v[mid + 1]) / 2;
        }
        return result;
    }
};

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        Solution ob;
        int ans = ob.find_median(v);
        cout << ans << "\n";
    }
    return 0;
}
