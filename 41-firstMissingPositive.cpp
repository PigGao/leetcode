class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int len = nums.size();
        if(len==0)
            return 1;
        if(len==1)
        {
            if(nums[0]==1)
                return 2;
            else
                return 1;
        }
        else
        {
            int pos;
            pos=findPosition(nums)+1;
            int count=1;
            while(pos<len)//越界判断应该在其他判断条件之前 
            {
                while(pos<len-1&&nums[pos+1]==nums[pos])
                    pos++;
                if(nums[pos]!=count)
                {
                    break;
                }
                if(nums[pos]==count)
                {
                    pos++;
                    count++;
                }
                    
            }
            
            return count;
        }
    }
    private:
    int findPosition(vector<int>& num)
    {
        int left=0;
        int right = num.size()-1;
        int mid;
        if(num[0]>0)
            return -1;
        if(num[right]<=0)
            return right-1;
        else
        {
            while(left<right)
            {
                mid = (left+right)/2;
                if(num[mid]>0)
                    right=mid;
                if(num[mid]<=0&&num[mid+1]>0)              
                    return mid;
                if(num[mid+1]<=0)
                    left=mid+1;
                    
            }
            
        }
        return left;
    }
};