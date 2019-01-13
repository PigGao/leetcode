#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;

class Solution
{
public:
	string convert(string s,int numRows){
		int size = s.length()/2+numRows;
		char a[numRows][size];
		for(int i=0;i<numRows;i++)
            for(int j=0;j<size;j++)
                a[i][j]='\0';
		string result="";
		int len = 2*(numRows-1);
		int num1,num2;
		int x,y;
        if(numRows==1)
            return s;
		for(int k=0;k<s.length();k++)
		{
			num1=k%len;
			num2=k/len;
			if(num1<numRows)
			{
				x=num1;
				y=num2*len/2;
				
			}
			if(num1>=numRows)
			{
				x=len-num1;
				y=num2*len/2+num1+1-numRows;
			}
			a[x][y]=s[k];
		}
			for(int i=0;i<numRows;i++)
				for(int j=0;j<size;j++)
				{
					if(a[i][j]!='\0')
						result += a[i][j];
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