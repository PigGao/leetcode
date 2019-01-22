class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> result;
        if(A.size()==0)
            return result;
        int tmp;
        for(int i=0;i<A.size();i++)
        {
            tmp = A[i]*A[i];
            result.push_back(tmp);
        }
        sort(result.begin(),result.end());
        return result;
    }
};
