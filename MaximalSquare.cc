class Solution {
public:
    
 
   int findSquare(vector<vector<char>>& matrix, int I, int J) {
        int ret = 0;
        int ROWS = matrix.size();
        int COLUMNS = matrix[0].size();
        int diff = 0;
        if (matrix[I][J] == '1') {
            ++diff;
            while(I+diff <= ROWS && J+diff <= COLUMNS) {
                int rows = I+diff;
                int columns = J+diff;
                bool isColumnsValid = true;
                for (int j = J; j < columns; ++j) {
                    if(matrix[rows-1][j] != '1') {
                        isColumnsValid = false;
                        break;
                    }
                }
            
                bool isRowsValid = true;
                if (isColumnsValid) {
                    for (int i = I; i < rows; ++i) {
                        if(matrix[i][columns-1] != '1') {
                            isRowsValid = false;
                            break;
                        }
                    }
                }
                if (!isColumnsValid || !isRowsValid) {
                    break;
                }
                ++diff;
            }
        }
        if (diff!=0)
            diff = diff-1;
        
        ret = diff * diff;
        return ret;
    }
    
        int maximalSquare(vector<vector<char>> matrix) {
        if (matrix.size() == 0) return 0;
        int ROWS = matrix.size();
        int COLUMNS = matrix[0].size();
        int maxSquare = 0;
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLUMNS; ++j) {
                int squareArea = findSquare(matrix, i, j);
                if (squareArea > maxSquare) {
                    maxSquare = squareArea;
                }
            }
        }
        return maxSquare;
    }
};