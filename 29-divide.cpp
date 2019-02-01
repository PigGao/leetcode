class Solution {
public:
    int divide(long long dividend, long long divisor) {
        int sign=1;
        //long long division=0;
        long long ans=0;
        if(divisor==0)
            return INT_MAX;
        if((dividend>=0&&divisor>0)||(dividend<0&&divisor<0))
            sign=1;
        if((dividend>=0&&divisor<0)||(dividend<0&&divisor>0))
            sign=-1;
        divisor = labs(divisor);
        dividend = labs(dividend);
        while(dividend>=divisor)
        {
            long long tmp=divisor;
            long long multiple=1;
            while((tmp<<1)<=dividend)
            {
                tmp = tmp<<1;
                multiple = multiple<<1;
            }
            dividend -=tmp;
            ans+=multiple;
        }
        if(sign==-1)
        {
            ans=0-ans;
        }
        if(ans>INT_MAX||ans<INT_MIN)
            return INT_MAX;
        return ans;
    }
};