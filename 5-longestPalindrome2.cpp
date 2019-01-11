#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>


using namespace std;

class Solution
{
public:
	string longestPalindrome(string s)
	{
		string result;
		if(s.length()<2)
			return s;
		int L = s.length();
		int start=0,end=0;
		for (int i =0;i<L;++i)
		{
			int len1 = maxlen(s,i,i);
			int len2 = maxlen(s,i,i+1);
			int len = max(len1,len2);
			if(len>end-start)
			{
				if(len%2==1)
				{
					start = i-len/2;
					end = i+len/2;
				}
				else
				{
					start = i-len/2+1;
					end = i+len/2;
				}
			}

		}
		result = s.substr(start,end-start+1);
		
		return result;
	}
private:
	int maxlen(string s,int left,int right)
	{
		int L = left ,R = right;
		while(L>=0&&R<s.length()&&s[L]==s[R])
		{
			L--;
			R++;
		}
		return R-L-1;
	}
	int max(int a,int b)
	{
		return a>b?a:b;
	}
};


int main()
{
	string s = "ukxidnpsdfwieixhjnannbmtppviyppjgbsludrzdleeiydzawnfmiiztsjqqqnthwinsqnrhfjxtklvbozkaeetmblqbxbugxycrlzizthtuwxlmgfjokhqjyukrftvfwikxlptydybmmzdhworzlaeztwsjyqnshggxdsjrzazphugckgykzhqkdrleaueuajjdpgagwtueoyybzanrvrgevolwssvqimgzpkxehnunycmlnetfaflhusauopyizbcpntywntadciopanyjoamoyexaxulzrktneytynmheigspgyhkelxgwplizyszcwdixzgxzgxiawstbnpjezxinyowmqsysazgwxpthloegxvezsxcvorzquzdtfcvckjpewowazuaynfpxsxrihsfswrmuvluwbdazmcealapulnahgdxxycizeqelesvshkgpavihywwlhdfopmmbwegibxhluantulnccqieyrbjjqtlgkpfezpxmlwpyohdyftzgbeoioquxpnrwrgzlhtlgyfwxtqcgkzcuuwagmlvgiwrhnredtulxudrmepbunyamssrfwyvgabbcfzzjayccvvwxzbfgeglqmuogqmhkjebehtwnmxotjwjszvrvpfpafwomlyqsgnysydfdlbbltlwugtapwgfnsiqxcnmdlrxoodkhaaaiioqglgeyuxqefdxbqbgbltrxcnihfwnzevvtkkvtejtecqyhqwjnnwfrzptzhdnmvsjnnsnixovnotugpzuymkjplctzqbfkdbeinvtgdpcbvzrmxdqthgorpaimpsaenmnyuyoqjqqrtcwiejutafyqmfauufwripmpcoknzyphratopyuadgsfrsrqkfwkdlvuzyepsiolpxkbijqw";
	string result;
	Solution test;
	result = test.longestPalindrome(s);
	cout << result << endl;
	return 0;
}