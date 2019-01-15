class Solution {
public:
    int romanToInt(string s) {
        unordered_map <char,int> m2 ={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int len=s.length();
        if(len==0)
            return 0;
        int i=0;
        int result=0;
        while(i<len)
        {
            if(m2[s[i]]<m2[s[i+1]])
            {
                result -= m2[s[i]];
                i++;
            }
            else
                result += m2[s[i++]];
        }
        return result;
    }
    
};