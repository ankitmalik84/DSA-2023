// no. 77
//  Counts Palindromic Subsequence in a given String
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*You are required to complete below method */
    // recursion + memoization
    // Ignore dp if you want to understand it through recursion first
    // int MOD = 1000000007;

    long long int solve(string &a, int i, int j, vector<vector<long long int>> &dp)
    {
        int MOD = 1000000007;
        if (i > j)
        {
            return 0;
        }
        if (i == j)
        {
            return 1;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int ans = 0;
        if (a[i] == a[j])
        {
            ans = (solve(a, i + 1, j, dp) + solve(a, i, j - 1, dp) + 1) % MOD;
        }
        else
        {
            ans = ((solve(a, i + 1, j, dp) + solve(a, i, j - 1, dp) - solve(a, i + 1, j - 1, dp) % MOD + MOD)) % MOD;
        }
        return dp[i][j] = ans;
    }
    // using tabulation
    long long int solve2(string &a)
    {
        int MOD = 1000000007;
        vector<vector<long long int>> dp(a.length() + 1, vector<long long int>(a.length() + 1, 0));
        //    Analyze base case
        for (int i = a.length() - 1; i >= 0; i--)
        {
            for (int j = i; j < a.length(); j++)
            {
                if (i == j)
                    dp[i][j] = 1;
                else if (a[i] == a[j])
                    dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] + 1) % MOD;
                else
                    dp[i][j] = ((dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1]) % MOD + MOD) % MOD;
            }
        }
        return dp[0][a.length() - 1];
    }
    long long int solve3(string &a)
    {
        int MOD = 1000000007;
        vector<long long int> curr(a.length() + 1, 0);
        vector<long long int> next(a.length() + 1, 0);
        for (int i = a.length() - 1; i >= 0; i--)
        {
            for (int j = i; j < a.length(); j++)
            {
                if (i == j)
                    curr[j] = 1;
                else if (a[i] == a[j])
                    curr[j] = (next[j] + curr[j - 1] + 1) % MOD;
                else
                    curr[j] = ((next[j] + curr[j - 1] - next[j - 1]) % MOD + MOD) % MOD;
            }
            next = curr;
        }
        return next[a.length() - 1];
    }
    long long int countPS(string str)
    {
        // vector<vector<long long int>> dp(str.length(),vector<long long int>(str.length(), -1));
        //   return solve(str,0,str.length()-1,dp);
        return solve3(str);
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
        long long int ans = ob.countPS(str);
        cout << ans << endl;
    }
}
