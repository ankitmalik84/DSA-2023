// Q39
// no. 52
//  kth largest element in a 2d array sorted row-wise and column-wise
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> mat[i][j];
        int r;
        cin >> r;
        cout << kthSmallest(mat, n, r) << endl;
    }
    // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
    return 0;
}

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    // Your code here
    // yaha hum assume karenge ki matrix ka first element hi smallest hoga aur last element hi maximum hoga-->
    int startVal = mat[0][0];
    int endVal = mat[n - 1][n - 1];
    int midVal;
    // yaha hum binary approach laga rahe h ki mid element nikal kr check karenge ki uss se chote kitne element hai
    // vo humare k no. of element k bara ya chote ya bade hai
    while (startVal <= endVal)
    {
        midVal = (startVal + endVal) / 2;
        // row wise traversing the matrix
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            // Applying binary search in each row
            int lo = 0, hi = n - 1, m;
            while (lo <= hi)
            {
                m = lo + (hi - lo) / 2;
                if (mat[i][m] <= midVal)
                    lo = m + 1;
                else
                    hi = m - 1;
            }
            ans += lo;
        }
        if (ans < k)
            startVal = midVal + 1;
        else
            endVal = midVal - 1;
    }
    return startVal;
}
