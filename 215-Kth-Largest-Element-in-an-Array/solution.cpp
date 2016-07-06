class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int loc = nums.size() - k;
        nth_element(nums.begin(), nums.begin()+loc, nums.end());
        return nums[loc];
    }
};