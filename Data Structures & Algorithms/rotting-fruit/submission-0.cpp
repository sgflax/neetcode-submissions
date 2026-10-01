class Solution {
private:
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int mins = 0;
        int fresh = 0;
        queue<pair<int, int>> q;

        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] == 1){
                    fresh++;
                } else if(grid[r][c] == 2){
                    q.push({r, c});
                }
            }
        }

        while(!q.empty() && fresh > 0){
            int length = q.size();
            for(int i = 0; i < length; i++){
                auto front = q.front();
                q.pop();

                for(int i = 0; i < 4; ++i){
                    int nr = front.first + directions[i][0];
                    int nc = front.second + directions[i][1];
                    if(nr >= 0 && nr < grid.size()
                        && nc >= 0 && nc < grid[0].size()
                        && grid[nr][nc] == 1){ //if neighbor fresh and in bounds
                        grid[nr][nc] = 2;
                        q.push({nr, nc}); //its now rotten, put in queue
                        fresh--;
                    }
                }
            }
            //gone through every orange in level, a minute passed
            mins++;
        }

        if(fresh==0){
            return mins;
        } else {
            return -1;
        }
        
    }
};
