// Q23
// no. 33
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find if there exists a triplet in the
    // array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        int start, end, sum = 0;
        sort(A, A + n);
        for (int i = 0; i < n; i++)
        {
            start = i + 1;
            end = n - 1;
            while (start < end)
            { // yaha hum 1 , 2 and end value ka sum nikalenge------->
                sum = A[i] + A[start] + A[end];
                // agar sum x k equal aa jaata hai toh hum true return kare denge
                if (sum == X)
                    return true;
                // agar sum x se chota hai toh hum start ko increase kar denge kyoki element sort hai toh first
                //  and element fix hai hum bich k element se hi try kr k dekhenge ki sum x k equal hota hai ya ni
                else if (sum < X)
                    start++;
                // agar sum x se bada ai toh hum end ko decrease karenge kyoki agar sum
                //  x se bada hai toh last k element ki vajah se jayada hoga kyoki element sort hai
                else
                    end--;
            }
        }
        // agar iterator yaha tak aata hai toh hmare koi triplet sum nhi hai------------>
        return false;
    }
};

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, X;
        cin >> n >> X;
        int i, A[n];
        for (i = 0; i < n; i++)
            cin >> A[i];
        Solution ob;
        cout << ob.find3Numbers(A, n, X) << endl;
    }
}
