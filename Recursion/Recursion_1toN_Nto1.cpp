#include <iostream>
using namespace std;
int printN_1(int num)
{
    if(num<1)
        return 1;
    else
        cout<<num<<"\n";
        return printN_1(num-1);

}
int print1_N(int i,int num)
{
    if(i>num)
        return 0;
    cout<<i<<"\n";
    return print1_N(i+1,num);

}

int main()
{
    int num;
    cout<<"Enter a number";
    cin>>num;
    cout<<"Numbers from 1 to "<<num<<endl;
    print1_N(1,num);
    cout<<"Numbers from  "<< num <<"to 1 \n";
    printN_1(num);

}
