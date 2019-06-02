class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int len = nums.size();
        int left=0,mid,right;
        sort(nums.begin(),nums.end());
        int sum;
        for(int i=0;i<len-3;i++)
        {
            sum = target-nums[i];
            if(i>0&&nums[i]==nums[i-1])
                continue;
            for(left=i+1;left<len-2;left++)
            {
                mid = left+1;
                right= len-1;
                int tmp = sum-nums[left];
                if(left>i+1&&nums[left]==nums[left-1])
                    continue;
                while(mid<right)
                {
                    if(nums[mid]+nums[right]==tmp)
                    {
                        int tmp_mid = nums[mid];
                        int tmp_right = nums[right];
                        int a[]={nums[i],nums[left],tmp_mid,tmp_right};
                        vector<int> v(a,a+4);
                        result.push_back(v);
                        while(mid<right&&nums[++mid]==tmp_mid);
                        while(mid<right&&nums[--right]==tmp_right);
                        
                    }
                    else if(nums[mid]+nums[right]>tmp)
                        right--;
                    else if(nums[mid]+nums[right]<tmp)
                        mid++;
                }
            }
        }
        return result;
    }
};