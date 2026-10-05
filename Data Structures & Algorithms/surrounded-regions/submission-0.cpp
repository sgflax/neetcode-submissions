class Solution {
public:
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void solve(vector<vector<char>>& board) {

        capture(board);

        for(int r = 0; r < board.size(); r++){
            for(int c = 0; c < board[0].size(); c++){
                if(board[r][c] == 'O'){
                    //we know its not on edge after capture
                    board[r][c] = 'X';
                } else if (board[r][c] == 'T'){
                    //it used to be an edge O
                    board[r][c] = 'O';
                }
            }
        }
    }

    void capture(vector<vector<char>>& board){
        queue<pair<int, int>> q;
        
        for(int r = 0; r < board.size(); r++){
            for(int c = 0; c < board[0].size(); c++){
                if(board[r][c] == 'O' &&
                    r == 0 || r == board.size() - 1 ||
                    c == 0 || c == board[0].size() - 1){
                    //if its O and on te edge
                    q.push({r, c});
                }
            }
        }


        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            if(board[row][col] == 'O'){
                //mark as visited
                board[row][col] = 'T';

                for(int i = 0; i < 4; i++){
                int nr = row + dirs[i][0];
                int nc = col + dirs[i][1];

                    if(nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size()){
                        q.push({nr, nc});
                    }
                }
            }
            
        }
    }
};
