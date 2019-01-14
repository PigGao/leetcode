//
//  main.cpp
//  IntegerToRoman
//
//  Created by 高志锋 on 2019/1/14.
//  Copyright © 2019年 高志锋. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;


class Solution {
public:
    
    string intToRoman(int num) {
        vector< vector<string> > nums(4,vector<string>(9,""));
        
        
        conver(0,'I','V','X',nums);
        conver(1,'X','L','C',nums);
        conver(2,'C','D','M',nums);
        nums[3][0]="M";
        nums[3][1]="MM";
        nums[3][2]="MMM";
        int temp[5]={0};
        string result="";
        int i=0;
        int x=num;
        while(x!=0)
        {
            temp[i]=x%10;
            x=x/10;
            i++;
        }
        for(int k=3;k>=0;k--)
        {
            if(temp[k]!=0)
            {
                result += nums[k][temp[k]-1];
            }
        }
        return result;
    }
private:
    void conver(int i,char a,char b,char c,vector< vector<string> > &nums){
        string temp="";
        temp.push_back(a);
        nums[i][0]=temp;
        nums[i][1]=nums[i][0]+a;
        nums[i][2]=nums[i][1]+a;
        temp.push_back(b);
        nums[i][3]=temp;
        temp=temp.substr(1,1);
        nums[i][4]=temp;
        nums[i][5]=nums[i][4]+a;
        nums[i][6]=nums[i][5]+a;
        nums[i][7]=nums[i][6]+a;
        temp.push_back(a);
        temp.push_back(c);
        temp=temp.substr(1,2);
        nums[i][8]=temp;
    }
};


int main()
{
    string result;
    int x=1973;
    Solution test;
    result = test.intToRoman(x);
    cout << result << endl;
    return 0;
}