//Q54
//no. 71
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        int i=0;
        stack<char>s;
        while(x[i]!='\0'){
             if(x[i]=='('||x[i]=='['||x[i]=='{'){
                s.push(x[i]);
            }
            else if(s.empty()){
                    return false;
                }
            else if(x[i]==')'){
                if(s.top()=='('){
                    s.pop();
                }
                else{
                    return false;
                }
            }
            else if(x[i]==']'){
                if(s.top()=='['){
                    s.pop();
                }
                else{
                    return false;
                }
            }
            else if(x[i]=='}'){
                if(s.top()=='{'){
                    s.pop();
                }
                else{
                    return false;
                }
            }
             i++;
        }
        if(s.empty()){
            return true;
        }
        else{
            return false;
        }   
    }
};

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}