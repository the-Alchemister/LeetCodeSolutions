/*
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.

Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

Note: The length of the given binary array will not exceed 50,000.
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // https://leetcode.com/articles/contiguous-array/
        int maxLen = 0, sum = 0;        
        map<int, int> sumIndex; // Sum - Index Map

        sumIndex[0] = -1; // For even array with same 0s and 1s
        
        for(int i=0; i<nums.size(); i++){
            sum += (nums[i] == 1) ? 1 : -1;    
            
            if(sumIndex.count(sum))
                maxLen = max(maxLen, i - sumIndex[sum]);
            else
                sumIndex[sum] = i;
        }
        return maxLen;
    }
};