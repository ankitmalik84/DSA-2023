#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    // Enter element in the first array...........
    cout << "Enter the number of element in the first array" << endl;
    cin >> n;
    int a[n];
    cout << "Enter the element in the first array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // Enter element in the second array........
    cout << "Enter the number of element in the second array" << endl;
    cin >> m;
    int b[m];
    cout << "Enter the element in the second array" << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    // initialize third array...
    int c[n + m];
    int k = 0;
    // element of first array in the third array
    for (int i = 0; i < n; i++)
    {
        c[k++] = a[i];
    }
    // element of second array in the third array
    for (int j = 0; j < m; j++)
    {
        int i;
        // check duplicates...
        for (i = 0; i < k; i++)
        {
            if (c[i] == b[j])
                break;
        }
        // if no duplicate present so i==k otherwise skip the element....
        if (i == k)
        {
            c[k++] = b[j];
        }
    }
    // print the union of the elements...
    for (int i = 0; i < k; i++)
    {
        cout << c[i] << " ";
    }
    return 0;
}