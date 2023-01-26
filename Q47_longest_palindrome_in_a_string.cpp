// Q47
// no. 63

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestPalin(string s)
    {
        int l, h;
        int start = 0, end = 1;
        for (int i = 1; i < s.length(); i++)
        {
            // even substring
            l = i - 1;
            h = i;
            while (l >= 0 && h < s.length() && s[l] == s[h])
            {
                if (h - l + 1 > end)
                {
                    start = l;
                    end = h - l + 1;
                }
                l--;
                h++;
            }

            // odd substring
            l = i - 1;
            h = i + 1;
            while (l >= 0 && h < s.length() && s[l] == s[h])
            {
                if (h - l + 1 > end)
                {
                    start = l;
                    end = h - l + 1;
                }
                l--;
                h++;
            }
        }
        string res;
        int k = 0;
        for (int i = start; i <= (start + end - 1); i++)
        {
            res.push_back(s[i]);
        }
        return res;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalin(S) << endl;
    }
}
