class Solution {
public:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int ROWS = heights.size();
        int COLS = heights[0].size();
        vector<vector<bool>> pac(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atl(ROWS, vector<bool>(COLS, false));

        queue<pair<int, int>> pac_q;
        queue<pair<int, int>> atl_q;

        for(int c = 0; c < COLS; c++){
            pac_q.push({0, c});
            atl_q.push({ROWS - 1, c});
        }
        for(int r = 0; r < ROWS; r++){
            pac_q.push({r, 0});
            atl_q.push({r, COLS - 1});
        }

        bfs(atl_q, atl, heights);
        bfs(pac_q, pac, heights);


        vector<vector<int>> res;
        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS; c++){
                if(pac[r][c] && atl[r][c]){
                    //can reach both pac and atl
                    res.push_back({r, c});
                }
            }
        }

        return res;
    }

    void bfs(queue<pair<int, int>>& q, vector<vector<bool>>& ocean, 
            vector<vector<int>>& heights){

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            //visited
            ocean[r][c] = true;

            for(int i = 0; i < 4; i++){
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];

                if(nr >= 0 && nr < heights.size()
                    && nc >= 0 && nc < heights[0].size()
                    && ocean[nr][nc] == false 
                    && heights[nr][nc] >= heights[r][c]){ //>= because were going baclwards
                    q.push({nr, nc});
                }
            }
        }
    }


};
