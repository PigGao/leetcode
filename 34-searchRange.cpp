class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size()-1;
        vector<int> ans(2,-1);
        if(n==-1||nums[n]<target)
            return ans;
        while(n>=0)
        {
            if(nums[n]==target)
            {
                ans[1]=n;
                while(n>0&&nums[n-1]==target)
                {
                    n--;
                }
                ans[0]=n;
                return ans;
            }
            if(nums[n]>target)
                n--;
            else
                return ans;
        }
        return ans;
    }
};