#include <iostream>
#include <algorithm>

using namespace std;

// length of result string should be equal to sum of two strings
bool checkLength(string first, string second, string result)
{
    if (first.length() + second.length() != result.length())
    {
        return false;
    }
    else
    {
        return true;
    }
}

// this method converts the string to char array
// sorts the char array
// convert the char array to string and return it
string sortString(string str)
{
    sort(str.begin(), str.end());
    return str;
}

// this method compares each character of the result with
// individual characters of the first and second string
bool shuffleCheck(string first, string second, string result)
{
    // sort each string to make comparison easier
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());
    sort(result.begin(), result.end());

    // variables to track each character of 3 strings
    int i = 0, j = 0, k = 0;

    // iterate through all characters of result
    while (k != result.length())
    {
        // check if first character of result matches
        // with first character of first string
        if (i < first.length() && first[i] == result[k])
            i++;

        // check if first character of result matches
        // with the first character of second string
        else if (j < second.length() && second[j] == result[k])
            j++;

        // if the character doesn't match
        else
        {
            return false;
        }

        // access next character of result
        k++;
    }

    // after accessing all characters of result
    // if either first or second has some characters left
    if (i < first.length() || j < second.length())
    {
        return false;
    }

    return true;
}

int main()
{
    string first = "XY";
    string second = "12";
    string results[] = {"1XY2", "Y1X2", "Y21XX"};

    // call the method to check if result string is
    // shuffle of the string first and second
    for (string result : results)
    {
        if (checkLength(first, second, result) == true && shuffleCheck(first, second, result) == true)
        {
            cout << result << " is a valid shuffle of " << first << " and " << second << endl;
        }
        else
        {
            cout << result << " is not a valid shuffle of " << first << " and " << second << endl;
        }
    }

    return 0;
}
