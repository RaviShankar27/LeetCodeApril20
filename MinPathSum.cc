class Solution {
public:
    //use Djkstra algorithm, when you reach sink , exit
 
    int minPathSum(vector<vector<int>> grid) {
        if (grid.size() == 0) return 0;
        int ROWS = grid.size();
        int COLUMNS = grid[0].size();
        pair<int,int> start(0,0), end(ROWS-1, COLUMNS-1);
        int minPath = grid[0][0];
        //Directed graph
        // outgoing edges (i, j+1), (i+1, j) , robable nodes to add in part1
        // incoming edges (i, j-1), (i-1, j) to update values on part2 nodes
        //update grid values
        
        vector<bool> visited;
        for (int index = 0; index < ROWS*COLUMNS; ++index) {
            visited.push_back(false);
        }
        
        vector<int> origValueOfGrid;
        for (int row = 0; row < ROWS; ++row) {
            for (int column = 0; column < COLUMNS; ++column) {
                origValueOfGrid.push_back(grid[row][column]);
            }
        }
        
        queue<pair<int,int>> Q;
        Q.push(start);
        visited[0] = true;
      
        int i =0, j = 0;
        while(!Q.empty()) {
            pair<int,int> front = Q.front();
            Q.pop();
            i = front.first, j = front.second;
            
            if (j+1 < COLUMNS && i< ROWS) {
                if (visited[i*COLUMNS+j+1]) {
                    //update to check with existing val and new val, min
                    if (grid[i][j] + origValueOfGrid[i*COLUMNS+j+1] <= grid[i][j+1]) {
                        grid[i][j+1] = grid[i][j] + origValueOfGrid[i*COLUMNS+j+1];
                    }
                }
                else {
                    Q.push(pair<int,int>(i,j+1));
                    grid[i][j+1] += grid[i][j];
                    visited[i*COLUMNS+j+1] = true;
                }
            }
                
            if (i+1 < ROWS && j < COLUMNS) {
                if (visited[(i+1)*COLUMNS+j]) {
                    if (grid[i][j] + origValueOfGrid[(i+1)*COLUMNS+j] <= grid[i+1][j]) {
                        grid[i+1][j] = grid[i][j] + origValueOfGrid[(i+1)*COLUMNS+j];
                    }
                }
                else {
                    Q.push(pair<int,int>(i+1,j));
                    grid[i+1][j] += grid[i][j];
                    visited[(i+1)*COLUMNS+j] = true;
                }
            }
        }

        return grid[ROWS-1][COLUMNS-1];
    }
};