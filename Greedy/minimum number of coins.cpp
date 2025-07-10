// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int AmountChanged(vector<int>&coins,int amount)
{
    sort(coins.begin(),coins.end());
    int ptr=coins.size()-1,count=0;
    while(ptr>=0)
    {
        while(amount>=coins[ptr])
        {
            amount-=coins[ptr];
            count++;
        }
        ptr--;
    }
    return amount<=0 ? count : -1;
}

int main() {
   //domination of coins given
   vector<int>arr={2,5};
  //Amount to be change
   int amt=3;
  //number of coins needed;
   cout<<AmountChanged(arr,amt);
    return 0;
}
