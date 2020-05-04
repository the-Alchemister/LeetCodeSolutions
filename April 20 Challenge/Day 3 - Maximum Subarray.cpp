/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = nums[0], cSum = nums[0];

        for(int i=1; i<n; i++){
            cSum   = max(nums[i], cSum + nums[i]);
            maxSum = max(maxSum , cSum);
        }
        return maxSum;
    }
};