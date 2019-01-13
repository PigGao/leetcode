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
		int n = s.length();
		int cyclelen=2*numRows-2;
		for(int i=0;i<numRows;i++)
			for(int j=0;j+i<n;j+=cyclelen)
			{
				result+=s[i+j];
				if(i!=0&&i!=numRows-1&&j+cyclelen-i<n)
				{
					result+= s[j+cyclelen-i];
				}
			}
		return result;

	}
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