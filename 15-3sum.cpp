#include <iostream>
#include <vector>
#include <math.h>


using namespace std;

class Solution
{
public:
    vector< vector<int> > threeSum(vector<int> &nums)
    {
        sort(nums.begin(),nums.end());
        unsigned long left,right;
        int sum;
        vector <int> temp(3);
        vector< vector<int> > result;
        unsigned long len = nums.size();
        for(int i=0;i<len&&nums[i]<=0;i++)
        {
            sum = 0-nums[i];
            left=i+1;
            if(i>0&&nums[i]==nums[i-1])
                continue;
            right = len-1;
            while(left<right)
            {
                if(nums[left]+nums[right]==sum)
                {
                    temp[0]=nums[i];
                    temp[1]=nums[left];
                    temp[2]=nums[right];
                    result.push_back(temp);
                    //tmp_left=nums[left];
                    //tmp_right=nums[right];
                    while(left<right&&nums[left]==temp[1])
                        ++left;
                    while(left<right&&nums[right]==temp[2])
                        --right;
                }
                else if(nums[left]+nums[right]<sum)
                    ++left;
                else 
                    --right;
            }
            
        }
        return result;
    }
    
};

int main()
{
    int a[]={-1,0,1,2,-1,-4};
    vector<int> b(a,a+6);
    Solution test;
    std::vector<std::vector<int> > v;
    v=test.threeSum(b);
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<3;j++)
            cout <<v[i][j]<<" ";
        cout << endl;
    }
    return 0;
    
}
