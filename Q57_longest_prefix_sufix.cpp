// Q57
// no. 74

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lps(string s)
    {
        int n = s.length();
        int i = 0, j = 1;
        int lps[n];
        lps[0] = 0;
        // phle hum ek array banayenge jisme hum repeation check karenge ki hmara pattern k kitne element aur kitni bar repeat ho ra hai
        while (j < n)
        {
            if (s[i] == s[j])
            {
                lps[j] = i + 1;
                i++;
                j++;
            }
            else
            {
                if (i == 0)
                {
                    lps[j] = 0;
                    j++;
                }
                else
                {
                    i = lps[i - 1];
                }
            }
        }
        return lps[n - 1];
    }
};

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
}
