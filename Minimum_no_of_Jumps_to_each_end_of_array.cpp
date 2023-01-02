#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minJumps(int a[], int n)
    {
        int i = 0, count = 0;
        if (n == 1)
            return 0;
        // if number of element is 1 then its already at the end so return 0
        while (1)
        {
            // if value element is zero and its not the last element then return -1
            if (a[i] == 0 && i < n - 1)
            {
                return -1;
            }
            // if its value is not zero and element is also not the last element that means there is jump
            count++;
            int m = 0;
            int j = i + 1;
            int index = j;
            // here we check the greatest element to jump on it by checking all the number
            for (int k = 0; k < a[i] && j < n; k++)
            {
                int temp = m;
                m = max(a[j] + k, m);
                // we do +k in this because as we move to the next element its position one step ahead from previous element
                // here we check if our destined position is change or not
                if (m != temp)
                {
                    index = j;
                }
                j++;
            }
            i = index;
            // here we check if our current jump make it to the last element or not
            if (j == n)
                break;
        }
        return count;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.minJumps(arr, n) << endl;
    }
    return 0;
}
