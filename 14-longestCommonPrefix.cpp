class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result="";
        char c;
        int flag=1;
        if(strs.size()==0)            
            return result;
        for(int i=0;i<strs[0].length();i++)
        {
            
            c=strs[0][i];

            for(int k=1;k<strs.size();k++)
            {
                if(strs[k][i]!=c)
                {
                    flag=0;
                    break;
                }
                
            }
            if(flag==0)
                break;
            result += c;
        }
        return result;
    }
};