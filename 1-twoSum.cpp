class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        vector<int> nums_sorted(nums.size());
        for(int i=0;i<nums.size();i++)
            nums_sorted[i]=nums[i];
        
        sort(nums_sorted.begin(),nums_sorted.end());
        vector <int> result;
        int a,b;
        while(left<right)
        {
            if(nums_sorted[left]+nums_sorted[right]==target)
            {
                a=nums_sorted[left];
                b=nums_sorted[right];
                break;
            }
            else if(nums_sorted[left]+nums_sorted[right]<target)
                left++;
            else if(nums_sorted[left]+nums_sorted[right]>target)
                right--;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==a||nums[i]==b)
                result.push_back(i);
        }
        return result;
    }
};