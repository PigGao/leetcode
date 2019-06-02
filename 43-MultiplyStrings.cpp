class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.length()-1;
        int n = num2.length()-1;
        int pos[m+n+2] = {0};
        for(int i=m;i>=0;i--)
            for(int j=n;j>=0;j--)
            {
                int mul = (num1[i]-'0')*(num2[j]-'0');
                int p1=i+j;
                int p2 = i+j+1;
                int sum = mul + pos[p2];
                pos[p1] += sum/10;
                pos[p2] = sum%10;
            }
        string res="";
        for(int p:pos)
        {
            if(p==0&&res.length()==0)
            {
                continue;
            }
            else
            {
                char c = '0'+p;
                res = res + c;
            }
                
        }
        return res.length()==0?"0":res;
    }
};