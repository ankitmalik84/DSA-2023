// Q36
// no. 48
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> sortedMatrix(int n, vector<vector<int>> mat)
    {
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                temp.push_back(mat[i][j]);
            }
        }
        sort(temp.begin(), temp.end());
        int counter = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mat[i][j] = temp[counter];
                counter++;
            }
        }
        return mat;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<vector<int>> v(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> v[i][j];
        Solution ob;
        v = ob.sortedMatrix(N, v);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << v[i][j] << " ";
            cout << "\n";
        }
    }
}