class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> mystack;
        int n = s.length();

        int maxlen=0;
        mystack.push(-1);
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
                mystack.push(i);
            if(s[i]==')')
            {
                mystack.pop();
                if(mystack.empty())
                    mystack.push(i);
                else
                    maxlen = max(maxlen,i-mystack.top());
            }
        }
        return maxlen;
    }
};