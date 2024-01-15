#include <iostream>
using namespace std;
long int fact(int num)
{
    if(num==0)
        return 1;
    else
        return(num*fact(num-1));
        
}

int main()
{
    int num;
    cout<<"Enter a number";
    cin>>num;
    if(num<1)
        cout<<"Please enter a postive integer";
    else
        cout<<"Factorial of "<<num<<endl;
        cout<<fact(num);
}
