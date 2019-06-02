class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        else
            return translate(countAndSay(n-1));
    }
private:
    string translate(string s)
    {
        string tmp="";
        int len = s.length();
        int i=1;
        int count=1;
        char a;
        while(i<len)
        {
            if(s[i]==s[i-1])
            {
                count++;
                i++;
            }
            else
            {
                a = '0'+count;
                tmp = tmp+a+s[i-1];
                i++;
                count = 1;
            }
            
        }
        a = '0'+count;
        tmp = tmp+a+s[i-1];
        return tmp;
    }
    
};