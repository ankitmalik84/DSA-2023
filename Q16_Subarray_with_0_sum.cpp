// Q16
//  A C++ program to find if there is a zero sum
//  subarray
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        // sabse phle hum check karenge ki koi zero toh present nhi hai array m agar hai toh hum tabhi true return kar denge
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
                return true;
        }
        // ek logic hota h ki agar kisi array m kuch elements ka sum zero hoga toh uska contigious sum nikalne pr koi bhie ke element repeat hota hai
        // jo element repeat hota hai iska matlab ki unke bich k elements ka sum zero tha
        vector<int> vec;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum = sum + arr[i];
            // agar sum starting k element m hi true hota hai toh yahi hum true return kar denge
            if (sum == 0)
                return true;
            vec.push_back(sum);
        }
        // yaha vector ko sort kar denge jis se repeat element find karne m easy ho
        sort(vec.begin(), vec.end());
        for (int i = 1; i < vec.size(); i++)
        {
            if (vec[i] == vec[i - 1])
                return true;
        }
        return false;
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
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        if (obj.subArrayExists(arr, n))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
