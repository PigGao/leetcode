class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        unordered_map <string,int> counts;
        int num = words.size();
        if(num==0)
            return ans;
        int n = s.length();
        int len = words[0].length();
        for(string word:words)
            counts[word]++;
        int i,j;
        unordered_map<string,int> seen;
        string temp;
        for(i=0;i<n-num*len+1;i++)
        {
            seen.clear();
            for(j=0;j<num;j++)
            
            {
                temp = s.substr(i+j*len,len);
                if(counts.find(temp)!=counts.end())
                {
                    seen[temp]++;
                    if(seen[temp]>counts[temp])
                        break;
                    
                }
                else
                    break;
            }
            if(j==num)
                ans.push_back(i);
            
        }
        return ans;
    }
};