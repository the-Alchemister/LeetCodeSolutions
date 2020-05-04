/*
First Bad Version
You are given an API bool isBadVersion(version) which will return whether version is bad. 
Implement a function to find the first bad version. You should minimize the number of calls to the API.

Example - 
Given n = 5, and version = 4 is the first bad version.
call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true
Then 4 is the first bad version. 
*/

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1, high = n, mid, res;
        while(low <= high) {
            mid = low + (high-low)/2;
            
            if(isBadVersion(mid))
                res = mid, high = mid - 1;
            else
                low = mid + 1;
        }
        return res;
    }
};