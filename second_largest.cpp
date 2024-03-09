#include <iostream>
using namespace std;

int main()
{
  int arr[6]={10,1,34,35,34,9};
  int max=INT_MIN;
  int secaond_max=INT_MIN;
  for(int i=0;i<n;i++)
    {
      if(arr[i}>max)
      {
        second_max=max;
        max=arr[i];
      }
      else if(arr[i]>second_max && arr[i]!=max) //if second_max < arr[i] < max need to update second max
      {
        second_max=arr[i];
      }
    }
  if(second_max != INT_MIN) return second_max;
  return -1;
  
}
