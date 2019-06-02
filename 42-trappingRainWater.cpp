class Solution {
public:
    int trap(vector<int>& height) {
        int max = 0;
        int maxID = 0;
        int result = 0;
        for(int i=0;i<height.size();i++)
        {
            if(height[i]>max)
            {
                max = height[i];
                maxID = i;
            }
        }
        int preHigh =0;
        for(int i=0;i<maxID;i++)//from left to highest position;
        {
            if(height[i]>preHigh)
                preHigh = height[i];
            result += preHigh -height[i];
        }
        preHigh=0;
        for (int i=height.size()-1;i>maxID;i--)
        {
            if(height[i]>preHigh)
                preHigh = height[i];
            result += preHigh -height[i];
        }
        return result;
    }
};