class Solution {
public:
    vector< vector<int> > grid;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        grid.assign(obstacleGrid.begin(),obstacleGrid.end());
        int R = grid.size();
        int C = grid[0].size();
        if(grid[0][0]==1)
            return 0;
        grid[0][0]=1;
        for(int i=1;i<R;i++)
        {
            if(grid[i][0]==0&&grid[i-1][0]==1)
                grid[i][0]=1;
            else
                grid[i][0]=0;
        }
        for(int i=1;i<C;i++)
        {
            if(grid[0][i]==0&&grid[0][i-1]==1)
                grid[0][i]=1;
            else
                grid[0][i]=0;
        }
        for(int r=1;r<R;r++)
            for(int c=1;c<C;c++)
            {
                if(grid[r][c]==0)
                    grid[r][c]=grid[r-1][c]+grid[r][c-1];
                else if(grid[r][c]==1)
                    grid[r][c]=0;
                
            }
        return grid[R-1][C-1];
    }
};