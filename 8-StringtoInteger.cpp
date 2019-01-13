#include <iostream>

using namespace std;


class Solution {
public:
    int myAtoi(string str) {
        long long result=0;
        int sign=1;
        int pos=0;
        if(str=="")
            return 0;
        while(str[pos]==' ')
            pos++;
        if(str[pos]=='-')
        {
            sign=-1;
            pos++;
        }
        if(str[pos]=='+'&&sign!=-1)
        {
            pos++;
        }
        int temp;
        if(str[pos]-'0'>9||str[pos]-'0'<0)
            return 0;
        for(int i=pos;i<str.length();i++)
        {
            temp = str[i]-'0';
            if(temp<0||temp>9)
                break;
            else
                result=result*10+temp;
            if(result>INT_MAX)
                break;
        }
        result*=sign;
        if(result<INT_MIN)
            return INT_MIN;
        else if(result>INT_MAX)
            return INT_MAX;
        else
            return result;

    }
};

int main()
{
    string s="  92233acbc72036854775808abc";
    Solution test;
    int result;
    result = test.myAtoi(s);
    cout << result<<endl;
    return 0;
}