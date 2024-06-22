#include <bits/stdc++.h>
using namespace std;

/* LCM (Least Common Multiple) of two numbers is the smallest number that is divisible by both numbers.*/
int main()
{
    int n1,n2;
    cout<<"Enter two number : ";
    cin>>n1>>n2;
    int product=n1*n2;
    while(n1!=0 && n2!=0) 
    {
        if(n1>n2)
        {
            n1=n1-n2; //n1%n2 better

        }
        else
        {
            n2=n2-n1; //n2%n1 better
        }
    }
    int gcd=1;
    if(n1!=0)
    {
        gcd=n1;
    }
    else
    {
        gcd=n2;
    }
    int lcm=product/gcd;
    cout<<lcm<<" "<<gcd;
    return 0;
}
    
