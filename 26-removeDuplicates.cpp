class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int i=1,j=1;
        int len = nums.size();
        if(len==0)
            return 0;
        while(j<len)
        {
            while(nums[j]==nums[j-1]&&j<len)
            {
                j++;
            }
            if(j<len)
            {
                nums[i]=nums[j];
                i++;
                j++;
            }
        }
        return i;
    }
};