// Q32
//  no. 42
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
    {
        // here we use 4 pointer approach
        vector<int> ans;
        int startrow = 0;
        int endrow = r - 1;
        int startcol = 0;
        int endcol = c - 1;

        while (startrow <= endrow && startcol <= endcol)
        {

            // from the starting row
            for (int i = startcol; i <= endcol; i++)
            {
                ans.push_back(matrix[startrow][i]);
            }
            startrow++;

            // from the ending col
            for (int i = startrow; i <= endrow; i++)
            {
                ans.push_back(matrix[i][endcol]);
            }
            endcol--;

            // from the ending row
            if (startrow <= endrow)
            {
                for (int i = endcol; i >= startcol; i--)
                {
                    ans.push_back(matrix[endrow][i]);
                }
                endrow--;
            }

            // from the starting column
            if (startcol <= endcol)
            {
                for (int i = endrow; i >= startrow; i--)
                {
                    ans.push_back(matrix[i][startcol]);
                }
                startcol++;
            }
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
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++)
        {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}