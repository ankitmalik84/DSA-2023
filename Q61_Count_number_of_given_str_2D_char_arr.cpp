// no.78

// yt solution

// #include <iostream>
// #include <bits/stdc++.h>
// int solve(int i, int j, string s, char ch[6][6], int size, int idx)
// {
//     int found = 0;
//     if (i >= 0 and j >= 0 and i < 6 and j < 6 and s[idx] == ch[i][j])
//     {
//         int temp = s[idx];
//         ch[i][j] = 0;
//         idx += 1;
//         if (idx == size)
//         {
//             found = 1;
//         }
//         else
//         {
//             found += solve(i + 1, j, s, ch, size, idx);
//             found += solve(i - 1, j, s, ch, size, idx);
//             found += solve(i, j + 1, s, ch, size, idx);
//             found += solve(i, j - 1, s, ch, size, idx);
//         }
//         ch[i][j] = temp;
//     }
//     return found;
// }

int main()
{
    string s = "GEEKS";
    char ch[6][6] = {
        {D, D, D, G, D, D},
        {B, B, D, E, B, S},
        {B, S, K, E, B, K},
        {D, D, D, D, D, E},
        {D, D, D, D, D, E},
        {D, D, D, D, D, G}
    } int ans = 0;
    int size = 5;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            ans += solve(i, j, s, ch, size, 0);
        }
    }
    cout << ans;

    return 0;
}

// algo------------------->
// Step 1– Traverse matrix character by character and take one character as string start
// Step 2– For each character find the string in all the four directions recursively
// Step 3– If a string found, we increase the count
// Step 4– When we are done with one character as start, we repeat the same process for the next character
// Step 5– Calculate the sum of count for each character
// Step 6– Final count will be the answer

// C++ code for finding count
// of string in a given 2D
// character array.
#include <bits/stdc++.h>
using namespace std;

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(*a))

// utility function to search
// complete string from any
// given index of 2d char array
int internalSearch(string needle, int row,
                   int col, string hay[],
                   int row_max, int col_max, int xx)
{
    int found = 0;

    if (row >= 0 && row <= row_max && col >= 0 &&
        col <= col_max && needle[xx] == hay[row][col])
    {
        char match = needle[xx];
        xx += 1;

        hay[row][col] = 0;

        if (needle[xx] == 0)
        {
            found = 1;
        }
        else
        {

            // through Backtrack searching
            // in every directions
            found += internalSearch(needle, row,
                                    col + 1, hay,
                                    row_max, col_max, xx);
            found += internalSearch(needle, row, col - 1,
                                    hay, row_max, col_max, xx);
            found += internalSearch(needle, row + 1, col,
                                    hay, row_max, col_max, xx);
            found += internalSearch(needle, row - 1, col,
                                    hay, row_max, col_max, xx);
        }
        hay[row][col] = match;
    }
    return found;
}

// Function to search the string in 2d array
int searchString(string needle, int row, int col,
                 string str[], int row_count,
                 int col_count)
{
    int found = 0;
    int r, c;

    for (r = 0; r < row_count; ++r)
    {
        for (c = 0; c < col_count; ++c)
        {
            found += internalSearch(needle, r, c, str,
                                    row_count - 1,
                                    col_count - 1, 0);
        }
    }
    return found;
}

int main()
{
    string needle = "MAGIC";
    string input[] = {"BBABBM",
                      "CBMBBA",
                      "IBABBG",
                      "GOZBBI",
                      "ABBBBC",
                      "MCIGAM"};
    string str[ARRAY_SIZE(input)];
    int i;
    for (i = 0; i < ARRAY_SIZE(input); ++i)
    {
        str[i] = input[i];
    }

    cout << "count: " << searchString(needle, 0, 0, str, ARRAY_SIZE(str), str[0].size()) << endl;
    return 0;
}
