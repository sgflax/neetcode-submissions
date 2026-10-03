class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] == 0){
                    q.push({r, c});
                }
            }
        }

        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = row + dirs[i][0];
                int nc = col + dirs[i][1];

                if(nr < 0 || nr >= grid.size() || nc < 0 || nc >= grid[0].size()
                    || grid[nr][nc] != 2147483647){
                        //not inbounds or not unvisited skip
                        continue;
                }

                grid[nr][nc] = grid[row][col] + 1;
                q.push({nr, nc});
            }

        }
    }
};
