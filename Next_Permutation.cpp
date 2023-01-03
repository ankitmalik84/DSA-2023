// leetcode
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        // phle hum longest non increasing suffix find karenge.....
        while (i >= 0 && nums[i + 1] <= nums[i]) {
            i--;
        }
        // indentify pivot element jp hmara suffix k first element se phela element hogaleft side
        if (i >= 0) {
            int j = nums.size() - 1;
            // find rightmost succesor to pivot in suffix
            while (nums[j] <= nums[i]) {
                j--;
            }
            // swap with pivot
            swap(nums[i], nums[j]);
        }
        // reverse kr denge suffix ko pivot k agle se lekar last tak
        reverse(nums.begin() + i + 1, nums.end());
    }
};