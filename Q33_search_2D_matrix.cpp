//Q33
// no.43

//Approach 1------------------------------>
class Solution {
public:
    // target > pivot-> r++
    // target < pivot-> c--
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=0,c = matrix[0].size()-1;
        while(r<matrix.size()&&c>=0){
            if(matrix[r][c]== target) return true;
            else if(matrix[r][c]<target) r++;
            else c--;
        }
        r=0;
        c=0;
        return false;
    }
};