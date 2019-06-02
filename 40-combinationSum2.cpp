
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> combinations;
        combinationSum(candidates,target,res,combinations,0);
        return res;
    }
    void combinationSum(vector<int>& candidates,int target,vector<vector<int>> &res,vector<int> &combinations,int begin)
    {
        if(target==0)
        {
            int flag=1;
            for(int i=0;i<res.size();i++)
            {
                if(res[i]==combinations)
                {
                    flag=0;break;
                }
            }
            if(flag==1)
                res.push_back(combinations);
            return;
        }
        for(int i=begin;i<candidates.size()&&target>=candidates[i];i++)
        {
            combinations.push_back(candidates[i]);
            combinationSum(candidates,target-candidates[i],res,combinations,i+1);
            combinations.pop_back();
        }
    }
};