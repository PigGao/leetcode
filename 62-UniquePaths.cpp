class Solution {
public:
    
    int uniquePaths(int m, int n) {
        vector<vector<int> > grid(m,vector<int> (n,0));
        for(int i=0;i<m;i++)
            grid[i][0]=1;
        for(int i=0;i<n;i++)
            grid[0][i]=1;
        for(int r=1;r<m;r++)
            for(int c=1;c<n;c++)
                grid[r][c]=grid[r-1][c]+grid[r][c-1];
        return grid[m-1][n-1];            
    }
};