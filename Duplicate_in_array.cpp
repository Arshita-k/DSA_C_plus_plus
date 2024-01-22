#include <bits/stdc++.h>
using namespace std;
int findDuplicate(vector<int> &arr) 
{
	int slow=arr[0];
	int fast=arr[arr[0]];
	while(fast!=slow)
	{
		slow=arr[slow];
		fast=arr[arr[fast]];
	}
	fast=0;
	while(slow!=fast)
	{
		slow=arr[slow];
		fast=arr[fast];
	}
	return slow;
}
int main()
{
    vector<int>arr={1,1,3,4,5};
    int n=findDuplicate(arr);
    cout<<n;
    return 0;
}
