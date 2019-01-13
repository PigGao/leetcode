class Solution {
public:
    bool isPalindrome(int x) {
        long long ret=0;
        int y=x;
        if(x<0)
            return false;
        int tmp;
        while(x!=0)
        {
            tmp=x%10;
            x/=10;
            ret = ret*10+tmp;
        }
        if(y==ret)
            return true;
        else
            return false;
    }
};