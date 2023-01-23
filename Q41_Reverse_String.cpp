//Q41
//no. 56
class Solution {
public:
    void reverseString(vector<char>& s) {
        //take first and last index
        int start =0,end=s.size()-1;
        while(start<end){
            //swap start and end index element of string and increse start and decrease end-------->
            swap(s[start],s[end]);
            start++;
            end--;
        }
    }
};