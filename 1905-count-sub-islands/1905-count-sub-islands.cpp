class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid2, vector<vector<int>>& grid1) {
        int m=grid1.size(); int n=grid1[0].size(); 
        int res=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid1[i][j]==1)
                {
                    res+= dfs(grid2,grid1,i,j);
                }
            }
        }
        return res;
    }
    
    int dfs(vector<vector<int>> &grid2, vector<vector<int>> &grid1, int i, int j)
    {
        int m = grid1.size(); int n = grid1[0].size();
        int res=1;
        
        if(i<0 || i==m || j<0 || j==n || grid1[i][j]==0) return 1;
        grid1[i][j]=0;
        res &= dfs(grid2, grid1, i-1,j);
        res &= dfs(grid2, grid1, i+1,j);
        res &= dfs(grid2, grid1, i,j-1);
        res &= dfs(grid2, grid1, i,j+1);
        return res & grid2[i][j];
        
    }
};