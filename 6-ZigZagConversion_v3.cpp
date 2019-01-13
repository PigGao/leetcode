#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;

class Solution
{
public:
	string convert(string s,int numRows){
		if(numRows==1)
			return s;
		string result="";
		std::vector<string> rows(min(numRows,int(s.length())));
		int currow=0;
		bool goingDown=false;
		for(char c:s)
		{
			rows[currow]+=c;
			if(currow==0||currow==numRows-1)
				goingDown=!goingDown;
			currow += goingDown?1:-1;
		}
		for(string row:rows)
			result+=row;
		return result;

	}
	//int min(int a,int b)
	//{
	//	return a<b?a:b;
	//}
};



int main()
{
	string s="PAYPALISHIRING";
	string result;
	Solution test;
	result=test.convert(s,3);
	cout << result << endl;

	return 0;	
}