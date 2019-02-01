class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0,j=0;
        int len = nums.size();
        if(len==0)
            return 0;
        for(i=0;i<len;)
        {
            if(nums[i]==val)
                i++;
            else
                nums[j++]=nums[i++];
        }
        return j;
    }
};