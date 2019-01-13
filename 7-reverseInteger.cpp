class Solution {
public:
    int reverse(int x) {
        long long result=0;
        int temp;
        int flag=1;
        if(x<0)
        {
            flag=-1;
            x=x*-1;
        }
        while(x!=0)
        {
            temp = x%10;
            x=x/10;
            result = result*10+temp;
        }
        result *= flag;
        if(result>INT_MAX||result<INT_MIN)
            return 0;
        else
            return result;
    }
};