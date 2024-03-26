#include <iostream>
// 1^1^3^3^4
//0^0^4=4
using namespace std;
int unique(int arr[],int n)
{
  int ans=0;
  for(int i=0;i<n;i++)
    {
      ans=ans^arr[i];
      //a^a=0
      //0^a=a
    }
  return ans;
}

int main()
{
  int n=5;
  int arr[n]={1,3,4,1,3};
  unique_element=unique(arr,n);
  cout<<unique_element;
  return 0;
}
