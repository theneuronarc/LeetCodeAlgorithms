class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)
            return 0;
            
        int rows = matrix.size() + 1;
        int cols = matrix[0].size() + 1;
        int squares[rows][cols] = {0};
        int maxSq = 0;
        for(int row = 0; row < rows; row++){
            for(int col = 0 ; col <  cols; col++){
                if(row == 0 || col == 0){
                    squares[row][col] = 0;
                    continue;
                }
                
                if(matrix[row - 1][col - 1] == '0'){
                    squares[row][col] = 0;
                }
                else{
                    int size = squares[row-1][col-1];
                    size = min(size, squares[row-1][col]);
                    size = min(size, squares[row][col-1]);
                    squares[row][col] = size + 1;
                }
                
                maxSq = max(maxSq, squares[row][col]);
            }
        }
        return maxSq*maxSq;
    }
};
