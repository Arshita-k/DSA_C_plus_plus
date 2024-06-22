#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n1,n2;
    cout<<"Enter two number : ";
    cin>>n1>>n2;
    int minimum=min(n1,n2); //because ofcourse a bigger number cannot completly divide a smaller number
    //HCF normal approach
    for(int i=minimum;i>0;i--)
    {
        if(n1%i==0 && n2%i==0)
        {
            cout<<i<<endl;
            break;
        }
    }
    //based on euclidean algorithm
    while(n1!=0 && n2!=0) //use and if anyone condition doesnot gets fulfilled then loop terminates 
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
    if(n1!=0)
        cout<<n1;
    else
        cout<<n2;
    return 0;
}
/* The Euclidean Algorithm is a method for finding the greatest common divisor of two numbers. 
It operates on the principle that the GCD of two numbers remains the same even if the smaller 
number is subtracted from the larger number. */
