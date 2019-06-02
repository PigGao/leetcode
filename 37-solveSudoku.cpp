class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        util(board,0);
    }
    bool util(vector<vector<char>>& board,int pos)
    {
        if(pos>=81)
            return true;
        int i = pos/9;
        int j = pos%9;
        if(board[i][j]!='.')
            return util(board,pos+1);
        else
        {
            for(char c='1';c<='9';c++)
            {
                if(isValid(board,i,j,c))
                {
                    board[i][j]=c;
                    if(util(board,pos+1))
                        return true;
                    else
                        board[i][j]='.';
                }
            }
        }
        return false;
    }
private:
    bool isValid(vector<vector<char>>& board,int row,int col,char c)
    {
        for(int i=0;i<9;i++)
        {
            if(board[i][col]!='.'&&board[i][col]==c) return false;
            if(board[row][i]!='.'&&board[row][i]==c) return false;
            if(board[(row/3)*3+i/3][3*(col/3)+i%3]!='.'&&board[(row/3)*3+i/3][3*(col/3)+i%3]==c) return false;
        }
        return true;
}
};