// Q35
//  no. 47
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> arr, int n, int m)
    {
        int col = m - 1;
        int row = -1;
        // traversing row by row
        for (int i = 0; i < n; i++)
        {
            // last column to first
            for (int j = col; j >= 0; j--)
            {
                if (arr[i][j] == 1)
                {
                    row = i;
                    // we will not see same column again
                    col--;
                }
                else
                {
                    break;
                }
            }
        }
        return row;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}