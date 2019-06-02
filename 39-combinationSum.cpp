class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> combinations;
        combination_Sum(candidates,target,res,combinations,0);
        return res;
    }
    void combination_Sum(vector<int> &candidates,int target,vector<vector<int>> &res,vector<int> &combinations,int begin)
    {
        if(target==0)
        {
            res.push_back(combinations);
            return;
        }
        for(int i=begin;i!=candidates.size()&&target>=candidates[i];i++)
        {
            combinations.push_back(candidates[i]);
            combination_Sum(candidates,target-candidates[i],res,combinations,i);
            for(int j=0;j<combinations.size();j++)
                cout << combinations[j] << " ";
            cout << endl;
            combinations.pop_back();
        }
    }
};