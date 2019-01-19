//
//  3-LengthOfLongestSubstring.cpp
//  LeetCode
//
//  Created by Ko Chi-fung on 2019/1/19.
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

class Solution
{
public:
    int threeSumClosest(vector<int> &nums,int target){
        int sum;
        int result=nums[0]+nums[1]+nums[2];
        long len = nums.size();
        long left,right,ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<len-2;i++)
        {
            left=i+1;
            right=len-1;
            sum = target-nums[i];
            ans=abs(result-target);
            while(left<right)
            {
                if(nums[left]+nums[right]==sum)
                    return target;
                while(nums[left]+nums[right]<sum&&left<right)
                {
                    if(ans>abs(sum-nums[left]-nums[right]))
                    {
                        result = nums[i]+nums[left]+nums[right];
                        ans = abs(sum-nums[left]-nums[right]);
                    }
                    left++;
                }
                while(nums[left]+nums[right]>sum&&left<right)
                {
                    if(ans>abs(sum-nums[left]-nums[right]))
                    {
                        result = nums[i]+nums[left]+nums[right];
                        ans = abs(sum-nums[left]-nums[right]);
                    }
                    right--;
                }
            }
            
        }
        return result;
    }
};

int main()
{
    vector<int> nums={0,1,2};
    Solution test;
    int result;
    result = test.threeSumClosest(nums, 1);
    cout << result <<endl;
    return 0;
}
