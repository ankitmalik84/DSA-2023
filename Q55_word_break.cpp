// Q55
// no. 72
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    unordered_map<string, int> dp;
    int solve(string s, vector<string> &b)
    {
        int sz = s.length();
        if (sz == 0)
            return 1;
        if (dp[s] != 0)
            return dp[s];
        // yaha pr hum phle s ka ek letter bhejenge aur usse match karayenge aur phir remaining then do letter then remaining....
        for (int i = 1; i <= sz; i++)
        {
            int f = 0;
            string ss = s.substr(0, i);
            for (int j = 0; j < b.size(); j++)
            {
                if (ss.compare(b[j]) == 0)
                {
                    f = 1;
                    break;
                }
            }
            // agar substr match ho jata hai toh f 1 ho jayega then remaining ko check karenge ki uska answer kya aa ra hai-------agar vo bhi 1 hai toh yani hume pura string mil ra hai
            if (f == 1 and solve(s.substr(i, sz - i), b) == 1)
                return dp[s] = 1;
        }
        // agra mera pura for loop chalne k baad bhi hume nhi mila then hum -1 return kar denge
        return dp[s] = -1;
    }
    int wordBreak(string A, vector<string> &B)
    {
        int x = solve(A, B);
        if (x == 1)
            return 1;
        else
            return 0;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> dict;
        for (int i = 0; i < n; i++)
        {
            string S;
            cin >> S;
            dict.push_back(S);
        }
        string line;
        cin >> line;
        Solution ob;
        cout << ob.wordBreak(line, dict) << "\n";
    }
}
