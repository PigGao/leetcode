//
//  main.cpp
//  UniquePathIII
//
//  Created by Ko Chi-fung on 2019/1/21.
//  Copyright © 2019 Ko Chi-fung. All rights reserved.
//
#include <vector>
#include <stdio.h>
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    int ans;
    vector< vector<int> > grid;
    int R,C;
    int sr=0,sc=0;
    int tr,tc;
    int dr[4]={0,1,0,-1};
    int dc[4]={1,0,-1,0};
    int uniquePathsIII(vector<vector<int> > &_grid) {
       // grid=_grid;
        grid.assign(_grid.begin(),_grid.end()); 
        R=grid.size();
        C=grid[0].size();
        int todo = 0;
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
            {
                if(grid[i][j]!=-1)
                    todo++;
                if(grid[i][j]==1)
                {
                    sr = i;
                    sc = j;
                }
                if(grid[i][j]==2)
                {
                    tr = i;
                    tc = j;
                }
            }
        ans=0;
        dfs(sr,sc,todo);
        return ans;
    }
    void dfs(int r,int c,int todo )
    {
        
        todo--;
        if(todo<0) return;
        if(r==tr&&c==tc)
        {
            if(todo==0)
                ans++;
            return;
        }
        grid[r][c]=3;
        for(int k=0;k<4;k++)
        {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if(nr>=0&&nr<R&&nc>=0&&nc<C)
            {
                if(grid[nr][nc]%2==0)
                    dfs(nr,nc,todo);
            }
        }
        grid[r][c]=0;
    }
};


int main()
{
    int a[3][4]={{1,0,0,0},{0,0,0,0},{0,0,0,2}};
    vector< vector<int> > grid(3);
    for(int i=0;i<3;i++)
        grid[i].resize(4);
    for(int i=0;i<3;i++)
        for(int j=0;j<4;j++)
            grid[i][j]=a[i][j];
    Solution test;
    int b;
    b = test.uniquePathsIII(grid);
    cout << b <<endl;
    return 0;
    
}

