class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0)
            return -1;
        int pos=nums.size()-1;
        while(nums[pos]>=nums[pos-1]&&pos>0)
            pos--;
        int n = nums.size()-1; 
        if(pos==0)
        {
            return find(nums,0,n,target);
        }
        if(nums[0]==target)
            return 0;
        if(nums[0]<target)
        {
            return find(nums,0,pos-1,target);
        }
        if(nums[0]>target)
        {
            return find(nums,pos,n,target);
        }
        return 0;
    }
private:
    int find(vector<int>& nums,int left,int right,int target)
    {
        int mid;
        while(left<=right)
        {
            mid = (left+right)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                left = mid+1;
            else if(nums[mid]>target)
                right = mid-1;
        }
        return -1;
    }
};