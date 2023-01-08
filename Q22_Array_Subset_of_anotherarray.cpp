// Q22
#include <bits/stdc++.h>
using namespace std;
string isSubset(int a1[], int a2[], int n, int m);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];
        for (int i = 0; i < n; i++)
        {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> a2[i];
        }
        cout << isSubset(a1, a2, n, m) << endl;
    }
    return 0;
}

// Approach 1---------------->
string isSubset(int a1[], int a2[], int n, int m)
{
    int i = 0;
    int j = 0;
    sort(a1, a1 + n);
    sort(a2, a2 + m);
    int count = 0;
    while (i < n && j < m)
    {
        if (a1[i] == a2[j])
        {
            count++;
            i++;
            j++;
        }
        else if (a1[i] < a2[j])
        {
            i++;
        }
        else if (a1[i] > a2[j])
        {
            j++;
        }
    }
    if (count == m)
    {
        return "Yes";
    }
    else
    {
        return "No";
    }
}
// Approach 2------------------>

// string isSubset(int a1[], int a2[], int n, int m) {
//      if(m>n) return "No";
//         map<int,int>maps;
//         for(int i=0; i<n; i++)
//         {
//             maps[a1[i]]++;
//         }
//         for(int i=0; i<m; i++)
//         {
//             //CONDITION ALSO CHECK FOR DUPLICATE IN a2
//             if(maps.find(a2[i])!=maps.end() && maps[a2[i]]>0)
//             {
//                 maps[a2[i]]--;
//             }
//            else  return "No";
//         }
//         return "Yes";
// }
