#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
	bool isMatch(string s,string p)
	{
		int m = s.length();
		int n = p.length();
		std::vector< std::vector<bool> > dp(m+1,vector<bool>(n+1,false));
		dp[0][0]=true;
		for(int i=0;i<=m;i++)
			for(int j=1;j<=n;j++)
			{
				if(p[j-1]=='*')
				{
					dp[i][j]=dp[i][j-2]||(i>0&&(s[i-1]==p[j-2]||p[j-2]=='.')&&dp[i-1][j]);
				}
				else
				{
					dp[i][j]=i>0&&dp[i-1][j-1]&&(s[i-1]==p[j-1]||p[j-1]=='.');
				}
			}
		return dp[m][n];
	}
};


int main()
{
	string s="mississippi";
	string p = "mis*is*ip*.";
	Solution test;
	if(test.isMatch(s,p))
		cout << "true"<<endl;
	else
		cout << "false" <<endl;
	return 0;
}