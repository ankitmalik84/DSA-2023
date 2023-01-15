// Q29
// no. 39
#include <iostream>
#include <string.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int m)
    {
        string b = to_string(m);
        int start = 0;
        int end = b.size() - 1;
        while (start < end)
        {
            if (b[start] == b[end])
            {
                start++;
                end--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    int PalinArray(int a[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (!isPalindrome(a[i]))
            {
                return 0;
            }
        }
        return 1;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.PalinArray(a, n) << endl;
    }
}