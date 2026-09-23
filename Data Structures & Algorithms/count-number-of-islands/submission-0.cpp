class Solution {
public:
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()){
            return 0;
        }

        int islands = 0;
        for(int r = 0; r < grid.size(); ++r){
            for(int c = 0; c < grid[0].size(); ++c){
                if(grid[r][c] == '1'){
                    bfs(grid, r, c);
                    islands++;
                }
            }
        }

        return islands;
    }

    void bfs(vector<vector<char>>& grid, int r, int c){
        //make r,c visited
        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] ='0';

        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int row = front.first;
            int col = front.second;

            //look at all neighbors of front
            for(int i = 0; i < 4; ++i){
                int neighbor_r = row + directions[i][0];
                int neighbor_c = col + directions[i][1];
                if(neighbor_r >= 0 && neighbor_c >= 0
                    && neighbor_r < grid.size() && neighbor_c < grid[0].size()
                    && grid[neighbor_r][neighbor_c] == '1'){
                        q.push({neighbor_r, neighbor_c});
                        grid[neighbor_r][neighbor_c] = '0';

                    }
            }
        }
    }
};
