// Q14
#include <bits/stdc++.h>
using namespace std;

// Approach 1......
class Solution
{
public:
    vector<int> commonElements(int a[], int b[], int c[], int n1, int n2, int n3)
    {
        // code here.
        int i = 0, j = 0, k = 0;
        vector<int> v;
        // given array sorted hai
        while (i < n1 && j < n2 && k < n3)
        {
            // agar sorted hai toh first element bhi common ho skta h
            if (a[i] == b[j] && b[j] == c[k])
            {
                v.push_back(a[i]);
                i++;
                j++;
                k++;
            }
            // agar first element sorted nhi hai toh jo element chota hoga uske index m increment kar denge
            else if (a[i] < b[j])
            {
                i++;
            }
            // same agar first element sorted nhi hai toh jo element chota hoga uske index m increment kar denge
            else if (b[j] < c[k])
                j++;
            else
                k++;
            // yaha hum check karenge ki increment k badd index ki value pichle common element k equal to nhi h agar hai toh hum increment kar denge
            int xx = a[i - 1];
            while (a[i] == xx)
                i++;
            int yy = b[j - 1];
            while (b[j] == yy)
                j++;
            int zz = c[k - 1];
            while (c[k] == zz)
                k++;
        }
        // agar sare process k baad vector empty() hai toh koi bhi common element nhi hai
        if (v.size() == 0)
            return {-1};

        return v;
    }

    // Approach 2---------------->
    /*
    vector <int> commonElements (int a[], int b[], int c[], int n1, int n2, int n3)
    {
        unordered_map<int,int> m1,m2,m3;
        //phle hum sare array k elements map m dal k frequency m increment kar denge------------->
        for(int i=0;i<n1;i++) m1[a[i]]++;
        for(int i=0;i<n2;i++) m2[b[i]]++;
        for(int i=0;i<n3;i++) m3[c[i]]++;
        vector<int> v;
        // yaha check karenge ki phle array k element teeeno map m hai agar hai toh usse vector m push kar denge
        for(int i=0;i<n1;i++){
            if(m1[a[i]]&&m2[a[i]]&&m3[a[i]]){
                v.push_back(a[i]);
                m1[a[i]]=0;
            }
        }
       return v;
    }
    */
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];

        for (int i = 0; i < n1; i++)
            cin >> A[i];
        for (int i = 0; i < n2; i++)
            cin >> B[i];
        for (int i = 0; i < n3; i++)
            cin >> C[i];

        Solution ob;

        vector<int> res = ob.commonElements(A, B, C, n1, n2, n3);
        if (res.size() == 0)
            cout << -1;
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
}