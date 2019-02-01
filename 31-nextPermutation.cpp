class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i=n-2;
        while(i>=0&&nums[i]>=nums[i+1])
            i--;
       if(i>=0) 
       {
          int j=n-1;
          while(j>=0&&nums[j]<=nums[i])
          j--;
          swap(nums,i,j);
       }
        reverse(nums,i+1,n-1);
        return;  
    }
    void swap(vector<int>& nums,int i,int j)
    {
        int temp;
        temp = nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
        return;
    }
    void reverse(vector<int> &nums,int start,int end)
    {
        while(start<end)
            swap(nums,start++,end--);
        return;
    }
};