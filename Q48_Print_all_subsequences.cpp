
#include <bits/stdc++.h>
using namespace std;

// Find all subsequences
void printSubsequence(int ind, vector<int> &ds, string input, int n)
{
    if (ind == n)
    {
        for (auto it : ds)
        {
            cout << it << " ";
        }
        if (ds.size() == 0)
        {
            cout << "{}";
        }
        cout << endl;
        return;
    }
    // take or pick the particular index into the subsequences
    ds.push_back(input[ind]);
    printSubsequence(ind + 1, ds, input, n);
    ds.pop_back();

    // not pick, or not take condition, this element is not added to your subsequence
    printSubsequence(ind + 1, ds, input, n);
}

int main()
{
    // output is set to null before passing in as a
    // parameter

    string input = "acbbd";
    vector<int> ds;
    int n = input.length();
    printSubsequence(0, ds, input, n);

    return 0;
}