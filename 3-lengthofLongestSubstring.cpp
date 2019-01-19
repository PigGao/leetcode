//
//  3-LengthOfLongestSubstring.cpp
//  LeetCode
//
//  Created by Ko Chi-fung on 2019/1/19.
//  Copyright © 2019 Ko Chi-fung. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string &s) {
        int maxlen=0;
        long n=s.size();
        cout <<n<<endl;
        if(0==n)
        {
            return maxlen;
        }
        unordered_map<char,int> mymap;
        int start=0;
        for(int i=0;i<n;i++)
        {
            if(mymap.find(s[i])!=mymap.end())
            {
                start=std::max(mymap.find(s[i])->second+1,start);
            }
            mymap[s[i]]=i;
            maxlen = max(i-start+1,maxlen);
        }
        return maxlen;
    }
};

int main()
{
    string s="abcabcbb";
    Solution test;
    int result;
    result = test.lengthOfLongestSubstring(s);
    cout << result <<endl;
    return 0;
}
