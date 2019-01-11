#include <iostream>
#include <string>
#include <math.h>


using namespace std;

class Solution
{
public:
	int maxlen=1;
	string tmp,str;
	int last,position;
	char a[1];
	string longestPalindrome(string s){
		if(s.length()==0)
			return "";
		string result=s.substr(0,1);
		//string tmp;
		for(int i=0;i<s.length()-maxlen;i++)
		{
			 tmp = Palind(s[i],i,s);
			 if(maxlen<tmp.length())
			 {
			 	maxlen = tmp.length();
			 	result = tmp;
			 	//cout <<"---"<<result<<endl;
			 }
			 else
			 	continue;
		}
		return result;
	} 
	string Palind(char c,int start,string s)
	{
		last=s.length()-1;
		position = s.find_last_of(s,last);
		str="";
		
		a[0] = c;
		if(position-start<maxlen)
			return str;
		if(position==start)
		{
			string t(a,1);
			str = t;
			return str;
		}
		else
		{
			if(isPalind(start,position,s))
			{
				str = s.substr(start,position-start+1);
				//cout << "-----"<<str<<" "<<str.length()<< endl;
				return str;
			}
			else
			{
				s=s.substr(0,position);
				return Palind(c,start,s);
			}
		}
		//return str;

	}
	bool isPalind(int pos1,int pos2,string str)
	{
		tmp = str;
		while(pos2>pos1)
		{
			if(tmp[pos2]!=tmp[pos1])
			{
				return false;
			}
			else if(tmp[pos2]==tmp[pos1])
			{
				pos2--;
				pos1++;
			}

		}
		return true;
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