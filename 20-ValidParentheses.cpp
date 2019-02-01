class Solution {
public:
    bool isValid(string s) {
        if(s.length()==0)
            return true;
        stack <char> mystack;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{')
            {
                mystack.push(s[i]);
            }
            else if(s[i]==')')
            {
                if(mystack.empty())
                    return false;
                char tmp = mystack.top();
                if(tmp!='(')
                    return false;
                mystack.pop();
            }
            else if(s[i]=='}')
            {
                if(mystack.empty())
                    return false;
                char tmp = mystack.top();
                if(tmp!='{')
                    return false;
                mystack.pop();
            }
            else if(s[i]==']')
            {
                if(mystack.empty())
                    return false;
                char tmp = mystack.top();
                if(tmp!='[')
                    return false;
                mystack.pop();
            }
        }
        if(!mystack.empty())
            return false;
        
        else
            return true;
    }
};