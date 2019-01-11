#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>

using namespace std;

class Solution
{
public:
	double findMedianSortedArrays(vector<int> &nums1,vector<int> &nums2)
	{
	double result;
	std::vector<int> temp;
	int i=0,j=0,k=0;
	int m=nums1.size();
	int n = nums2.size();
	while(i<m||j<n)
	{
		if(i==m&&j<n)
			temp.push_back(nums2[j++]);
		else if(j==n&&i<m)
			temp.push_back(nums1[i++]);
		else if(nums1[i]<=nums2[j])
			temp.push_back(nums1[i++]);
		else
			temp.push_back(nums2[j++]);
	}
	//for(k=0;k<m+n;k++)
	//	cout << temp[k]<<" ";
	//cout << endl;
	k=(m+n)/2;
	if((m+n)%2==0)
		result = double(temp[k-1]+temp[k])/2;
	else
		result = temp[k];
	return result;
	}
};

int main()
{
	
	int a[]={1,2};
	int b[]={3};
	vector<int> nums1(a,a+2);
	vector<int> nums2(b,b+1);
	Solution test;
	double result;
	result = test.findMedianSortedArrays(nums1,nums2);
	cout << result <<endl;
	system("pause");
	return 0;

}