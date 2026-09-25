class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //check each row, else move to next row
        int top = 0;
        int bot = matrix.size() - 1;
        int cols = matrix[0].size();

        while(top <= bot){
            int row = (top + bot) / 2;

            if(matrix[row][cols - 1] < target){
                top = row + 1;
            } else if (matrix[row][0] > target){
                bot = row - 1;
            } else {
                break;
            }
        }

        int row = (top + bot) / 2;

        int l = 0;
        int r = cols - 1;

        while(l <= r){
            int mid = (l + r) / 2;

            if(matrix[row][mid] == target){
                return true;
            } else if (matrix[row][mid] < target){
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        
        return false;
    }
};
