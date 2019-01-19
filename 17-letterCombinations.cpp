class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.length()==0)
            return result;
        static const vector<string> v = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        result.push_back("");
        for(int i=0;i<digits.length();i++)
        {
            int num = digits[i]-'0';
            
            if(v[num].length()==0)
                continue;
            vector<string> tmp;
            for(int k=0;k<v[num].length();k++)
                for(int j=0;j<result.size();j++)
                    tmp.push_back(result[j]+v[num][k]);
            result.swap(tmp);
        }
        
        return result;
    }
};