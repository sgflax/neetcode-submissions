class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_map<int, unordered_set<char>> row;
        unordered_map<int, unordered_set<char>> col;
        map<pair<int, int>, unordered_set<char>> square;


        for(int r = 0; r < 9; ++r){
            for(int c = 0; c < 9; ++c){
                if(board[r][c] != '.'){
                    pair<int, int> sk = {r/3, c/3};

                    if(row[r].contains(board[r][c])){
                        return false;
                    }
                    if(col[c].contains(board[r][c])){
                        return false;
                    }
                    if(square[sk].contains(board[r][c])){
                        return false;
                    }

                    row[r].insert(board[r][c]);
                    col[c].insert(board[r][c]);
                    square[sk].insert(board[r][c]);
                }
            }
            
        }
        return true;

    }
};
