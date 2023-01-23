//Q42
//no.57
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:	
	//similar approach as last question	
	int isPalindrome(string s)
	{
	    int start=0,end=s.size()-1;
	    while(start<end){
	        if(s[start++]!=s[end--]){
	            return 0;
	        }
	    }
	    return 1;
	}

};

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}