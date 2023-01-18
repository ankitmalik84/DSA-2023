// Q34
// no. 46
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int median(vector<vector<int>> &matrix, int R, int C)
    {
        // yaha hum ek vector banayenge
        vector<int> ans;
        // sare element vector m store karenge
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                ans.push_back(matrix[i][j]);
            }
        }
        // yaha hum mid index nikalenge vector ka
        int size = ans.size() / 2;
        sort(ans.begin(), ans.end()); // vector ko sort kar denge
        // yaha hum mid element return kar denge
        return ans[size];
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        cout << obj.median(matrix, r, c) << endl;
    }
    return 0;
}