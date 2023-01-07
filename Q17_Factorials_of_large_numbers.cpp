// Q17

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> factorial(int N)
    {
        // hum ans vector store karenge kyoki result ka size long long int se bhi bada ho skta hai
        vector<int> ans;
        // starting m carry 0 hoti hai
        int carry = 0, prod = 0;
        ans.push_back(1);
        for (int i = 2; i <= N; i++)
        {
            for (int j = 0; j < ans.size(); j++)
            {
                prod = ans[j] * i + carry;
                ans[j] = prod % 10;
                carry = prod / 10;
            }
            // agar last wale element m koi carry hai to
            while (carry > 0)
            {
                prod = carry % 10;
                ans.push_back(prod);
                carry = carry / 10;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
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
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i)
        {
            cout << result[i];
        }
        cout << endl;
    }
    return 0;
}

// explain approach
/*
Example to show working of multiply(res[], x)

A number 5189 is stored in res[] as following: res[] = {9, 8, 1, 5}
let x = 10
Initialize carry = 0

At i = 0, prod = res[0]*x + carry = 9*10 + 0 = 90.
res[0] = 0, carry = 9

At i = 1, prod = res[1]*x + carry = 8*10 + 9 = 89
res[1] = 9, carry = 8

At i = 2, prod = res[2]*x + carry = 1*10 + 8 = 18
res[2] = 8, carry = 1

At i = 3, prod = res[3]*x + carry = 5*10 + 1 = 51
res[3] = 1, carry = 5

res[4] = carry = 5
res[] = {0, 9, 8, 1, 5}


*/