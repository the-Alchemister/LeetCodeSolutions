/*
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. 
Check if these points make a straight line in the XY plane.


Example 1:
Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true

Example 2:
Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false 

Constraints:
	2 <= coordinates.length <= 1000
	coordinates[i].length == 2
	-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
	coordinates contains no duplicate point.
*/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coords) {
        int N = coords.size();
        if(N == 2)
            return true;
        
        float m = 1.0 * (coords[1][1] - coords[0][1]) / (coords[1][0] - coords[0][0]);
        
        for(int i = 2; i < N; i++) {
            float curM =  1.0 * (coords[i][1] - coords[i-1][1]) / (coords[i][0] - coords[i-1][0]);
                
            if(m != curM)
                return false;
        }
        return true;
    }
};