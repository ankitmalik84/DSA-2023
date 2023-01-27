//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
		void helper(int count[],vector<string>&ans,int index,int &n,string &asf) {
	    if(index==n) {
	        ans.push_back(asf);
	        return;
	    }
	    for(int i=0;i<122;i++) {
	        if(count[i]>0) {
	            count[i]--;
	            asf.push_back(char(i));
	            helper(count,ans,index+1,n,asf);
	            asf.pop_back();
	            count[i]++;
	        }
	    }
	}
	vector<string>find_permutation(string s) {
	    string asf="";
	    vector<string>ans;
	    int count[122]={0},n=s.length();
	    for(int i=0;i<s.length();i++) {
	        count[s[i]]++;
	    }
	    helper(count,ans,0,n,asf);
	    return ans;
	}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends