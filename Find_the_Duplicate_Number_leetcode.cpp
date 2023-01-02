// Approach 1 Official leetcode----------
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        while (nums[0] != nums[nums[0]])
            swap(nums[0], nums[nums[0]]);
        return nums[0];
    }
};

// Approach 2 By me--------
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int duplicate = 0;

        // sort the vector
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++)
        {
            // if two consecutive elements are equal
            // you have find a duplicate
            // break the loop
            if (nums[i] == nums[i + 1])
            {
                duplicate = nums[i];
                break;
            }
        }
        // return duplicate value
        return duplicate;
    }
};