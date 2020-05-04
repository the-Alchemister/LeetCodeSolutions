/*
Given a positive integer, output its complement number. 
The complement strategy is to flip the bits of its binary representation.

Example 1:
Input: 5 (101)
Output: 2 (010)

Example 2:
Input: 1 (01)
Output: 0 (00)
*/
  

class Solution {
public:
    int findComplement(int N) {
        if(N == 0)
            return 1;
        
        int i = 0, res = 0;
        while (N) {
            if (N % 2 == 0) 
                res += 1 << i;
            
            N = N / 2;
            i++;
        }
        return res;
    }
};