/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:
Input: 16
Output: true

Example 2:
Input: 14
Output: false
*/

class Solution {
public:
    bool isPerfectSquare(int num) {        
        if(num == 0)
            return false;
        
        long low = 1, high = num, mid;
    
        // 1 2 3 4 5 6 7 8 9
        // ^       *       ^  
        // ^ *   ^   
        //     ^ ^
        
        while(low <= high) {
            mid = low + (high - low)/2;
            
            if(mid * mid == num)
                return true;
            else if(mid * mid > num)
                high = mid - 1;
            else
                low  = mid + 1;
        }
        return false;
    }
};