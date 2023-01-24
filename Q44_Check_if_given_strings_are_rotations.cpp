// Q44
// no. 60

#include <bits/stdc++.h>
using namespace std;

bool check_rotation(string s, string goal)
{
    // agar dono string ka size equal nhi hai toh vo rotation nhi hoga
    if (s.size() != goal.size())
        return false;
    // yaha hum dono string ko queue m dal denge
    queue<char> q1;
    for (int i = 0; i < s.size(); i++)
    {
        q1.push(s[i]);
    }

    queue<char> q2;
    for (int i = 0; i < goal.size(); i++)
    {
        q2.push(goal[i]);
    }

    int k = goal.size();
    while (k--)
    {
        // yaha goal wali string ka first
        // element nikal k last m push karte rahenge aur check karenge ki length of
        // string tak ki rotation m vo string k equal aata hai toh vo rotation hoga
        char ch = q2.front();
        q2.pop();
        q2.push(ch);
        if (q2 == q1)
            return true;
    }
    return false;
}

int main()
{
    string str1 = "AACD", str2 = "ACDA";

    if (check_rotation(str1, str2))
        printf("Strings are rotations of each other");
    else
        printf("Strings are not rotations of each other");
    return 0;
}
