class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m = len(s)
        n = len(p)
        if m==0 and n==0:
            return True   
        P = [[False for i in range(n+1)] for j in range(m+1)]
        P[0][0] = True
        for i in range(0,m+1):
            for j in range(1,n+1):
                if p[j-1]=='*':
                    P[i][j] = P[i][j-1] or (i>0 and P[i-1][j])
                if p[j-1]!='*':
                    P[i][j] = i>0 and P[i-1][j-1] and (s[i-1]==p[j-1] or p[j-1]=='?')
        return P[m][n]