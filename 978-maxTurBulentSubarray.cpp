//
//  main.cpp
//  maxTurbulenceSize.cpp
//
//  Created by Ko Chi-fung on 2019/1/20.
//  Copyright © 2019 Ko Chi-fung. All rights reserved.
//


#include <vector>
#include <stdio.h>
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int maxlen=1;
        if(A.size()==1)
            return 1;
        if(A.empty())
            return 0;
        int len = A.size();
        int pos=0;
        //compare(A[pos],A[pos-1]);
        for(int i=1;i<len;i++)
        {
            
            int c = compare(A[i-1], A[i]);
            if(i==len-1||c*compare(A[i],A[i+1])!=-1)
            {
                maxlen = max(maxlen,i-pos+1);
                pos = i;
            }
            
        }
        return maxlen;
    }
private:
    int compare(int a,int b)
    {
        if(a>b)
            return -1;
        if(a<b)
            return 1;
        if(a==b)
            return 0;
        return 0;
    }
};
int main()
{
    vector<int> A = {4,8,3,12,16};
    Solution test;
    int result;
    result = test.maxTurbulenceSize(A);
    cout << result << endl;
    return 0;
}
