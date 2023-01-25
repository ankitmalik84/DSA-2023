// iss question hum ek tarah se FE ka combination follow kar rahe hai phle frequency then element
// jaise yaha ek function hai count_and_say()
// agar say(1)-->"1"      ise hum keh skte h one times one so "11"
// agar say(2)-->"11"     ab yaha piche dekho last hmara ans 1 tha toh usse hum "11" keh skte h toh ye hmara amswer hoga
//                        aur iss wale function ka answer hoga two times one "21"
// agar say(3)-->21     ab yaha piche dekho last hmara ans 11 tha toh usse hum "21" keh skte h toh ye hmara amswer hoga
//                        aur iss wale function ka answer hoga one times two aur one time one "1211"
// agar say(4)-->1211     ab yaha piche dekho last hmara ans 21 tha toh usse hum "1211" keh skte h toh ye hmara amswer hoga
//                        aur iss wale function ka answer hoga one times one aur one time two aur two time one "111221"

class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        // Recursion
        string s = countAndSay(n - 1);
        int count = 0;
        string res = "";
        for (int i = 0; i < s.length(); i++)
        {
            count++;
            // Segregating into groups
            if (i == s.length() - 1 || s[i] != s[i + 1])
            {
                res = res + to_string(count) + s[i];
                count = 0;
            }
        }
        return res;
    }
};

// using chatGPT
class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        string s = "1";
        for (int i = 2; i <= n; i++)
        {
            int count = 1;
            string temp = "";
            for (int j = 1; j < s.length(); j++)
            {
                if (s[j] == s[j - 1])
                {
                    count++;
                }
                else
                {
                    temp += to_string(count) + s[j - 1];
                    count = 1;
                }
            }
            temp += to_string(count) + s[s.length() - 1];
            s = temp;
        }
        return s;
    }
};
