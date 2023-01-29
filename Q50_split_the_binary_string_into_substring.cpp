// Q50
// no. 67
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubStr(string s)
    {
        int n = s.length();
        int x = 0, y = 0, c = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                x++;
            else
                y++;
            if (x == y)
                c++;
        }
        if (x != y)
        {
            return -1;
        }

        return c;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.maxSubStr(str);
        cout << ans << endl;
    }
    return 0;
}
