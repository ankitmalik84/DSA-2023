// Q31
// no. 41

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int> &array1, vector<int> &array2);

class Solution
{
public:
    double MedianOfArrays(vector<int> &arr1, vector<int> &arr2)
    {

        int j = arr2.size();
        int a = 0;
        for (int k = 0; k < j; k++)
        {
            arr1.push_back(arr2[k]);
        }
        sort(arr1.begin(), arr1.end());
        int size = arr1.size();
        int mid = size / 2;
        if (size % 2 == 0)
        {
            return ((arr1[mid] + arr1[mid - 1]) / 2.0);
        }
        else
        {
            return arr1[mid];
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i)
        {
            cin >> array1[i];
        }
        cin >> n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> array2[i];
        }
        Solution ob;
        cout << ob.MedianOfArrays(array1, array2) << endl;
    }
    return 0;
}
