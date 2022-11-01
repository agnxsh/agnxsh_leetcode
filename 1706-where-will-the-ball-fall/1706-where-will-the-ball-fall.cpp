class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> result(grid[0].size(),0);
        for(int col =0; col<grid[0].size();col++)
        {
            int currentColumn = col;
            for(int row=0; row<grid.size();row++)
            {
                int nextColumn = currentColumn + grid[row][currentColumn];
                if(nextColumn < 0 || nextColumn > grid[0].size()-1 || grid[row][currentColumn] != grid[row][nextColumn])
                {
                    result[col]=-1;
                    break;
                }
                result[col]=nextColumn;
                currentColumn = nextColumn;
            }
        }
        return result;
    }
};