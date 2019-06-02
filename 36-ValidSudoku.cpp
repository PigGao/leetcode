class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9]={0};
        int column[9][9]={0};
        int box[9][9]={0};
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    int num = board[i][j]-'0'-1;
                    int k = i/3*3+j/3;
                    if(rows[i][num]||column[j][num]||box[k][num])
                        return false;
                    else
                        rows[i][num]=1;
                        column[j][num]=1;
                        box[k][num]=1;
                }
            }
        }
        return true;
    }
};