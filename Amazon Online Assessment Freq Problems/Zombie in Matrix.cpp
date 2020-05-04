/*
https://leetcode.com/discuss/interview-question/411357

Given a 2D grid, each cell is either a zombie 1 or a human 0. 
Zombies can turn adjacent (up/down/left/right) human beings into zombies every hour. 
Find out how many hours does it take to infect all humans?
*/
#include<bits/stdc++.h>
using namespace std;

int minHours (int rows, int columns, vector<vector<int>>& grid) {
    if (grid.empty()) return 0;
    queue<pair<int, int>> q;
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    for (int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
            if (grid[i][j]==1) q.push({i, j});
        }
    }
    
    int hours = -1;
    while (!q.empty()) {
        int size = q.size();
        for (int i=0; i<size; i++) {
            auto cur = q.front();
            q.pop();
            for (auto dir: dirs) {
                int nr = cur.first+dir[0];
                int nc = cur.second+dir[1];
                if (nr>=0 && nr<rows && nc>=0 && nc<columns && grid[nr][nc]==0) {
                    q.push({nr, nc});
                    grid[nr][nc] = 1;
                }
            }   
        }
        hours++;
    }
    
    return hours;
}
int main() {
    vector<vector<int>> grid = {
        {0, 1, 1, 0, 1},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0},
    };
    int row = grid.size(), col = grid[0].size();
    cout << minHours(row, col, grid) << endl;
    
    return 0;
}