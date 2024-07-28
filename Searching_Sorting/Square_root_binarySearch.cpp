#include <bits/stdc++.h>
using namespace std;
//Function to find integer part of the root if a perfect square root is not found this function returns floor value of sqquare root
long long int squareroot(long long int x)
{
    int start = 1;
    long long int end=x;
    long long int mid=start + (end-start)/2;
    long long int answer=-1;
    while(start<=end)
    {
        long long int square=mid*mid;
        if(square==x)
        {
            return mid;
        }
        else if(square<x)
        {
            answer=mid;
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
        mid = start + (end-start)/2;
    }
   return answer;
}
//function to print the decimal part of square root of non perfect square numbers
// its like first checking for eg. root is 6 then (6.0)^2 < 37 then (6.1)^2 <37 [by adding j+factor j is 6 and factor is 0,0.1,0.2 then in next loop 0.01,0.02 and so on]
double getPrecision(long long int root, int limit, long long int number)
{
    double factor=1;
    double answer=root;
    for(int i = 0; i < limit ; i++)
    {
        factor=factor/10;  // To add 0.1 then 0.01 then 0.001 and so on and check for the precision till the limit of decimal 
        for(double j=answer;j*j<number;j=j+factor)
        {
            answer=j; // if the square root does not correspond to the given number the loop terminates according the condition j*j<number
        }
    }
    return answer;
}
int main()
{
    long long int n=37;
    long long int intergerSol=squareroot(n);
    cout<<intergerSol<<endl;
    cout<<"Square root of n = 37 to precision till 3 decimal point is  "<<getPrecision(intergerSol,3,n)<<endl;
    return 0;
}
