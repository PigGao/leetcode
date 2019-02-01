class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        if(n==0)
            return 0;
        int pos;
        pos = haystack.find(needle);
        if(pos!=string::npos)
            return pos;
        else
            return -1;
    }

};