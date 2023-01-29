// Q52
// no.69
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(string &a, string &b, int i, int j, vector<vector<int>> &dp)
    {
        if (i == a.length())
        {
            //   agar i traverse karte karte a word se aage nikal jata h toh rem operation kya honge b ki len- i
            return b.length() - j;
        }
        if (j == b.length())
        {
            return a.length() - i;
        }
        // agar hmara element dp m present hai toh hum aage process hi nhi karenge
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int ans = 0;
        //   agar letter match kar jaye
        if (a[i] == b[j])
        {
            return solve(a, b, i + 1, j + 1, dp);
        }
        else
        {
            // insert
            int insertAns = 1 + solve(a, b, i, j + 1, dp);
            // delete
            int delAns = 1 + solve(a, b, i + 1, j, dp);
            // replace
            int repAns = 1 + solve(a, b, i + 1, j + 1, dp);

            ans = min(insertAns, min(delAns, repAns));
        }
        return dp[i][j] = ans;
    }
    int editDistance(string s, string t)
    {
        // initialize dp
        vector<vector<int>> dp(s.length(), vector<int>(t.length(), -1));
        return solve(s, t, 0, 0, dp);
    }
};

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
