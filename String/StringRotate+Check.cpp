#include <bits/stdc++.h>
using namespace std;
// Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
// A shift on s consists of moving the leftmost character of s to the rightmost position.
// For example, if s = "abcde", then it will be "bcdea" after one shift.
//lets do two type one check if it is rotation other left rotate the string as well as right rotate 

string isrotateString(string s,string goal)
{
    if(s.length()!=goal.length()) return "No";
    //Check whether one string is rotation of another string
    string str=s+s; //abcde + abcde = abcdeabcde 
    if(str.find(goal) != string::npos)
        return "Yes";
        
    return "No";
}
void leftrotate(string s, int pos)
{
    int len=s.length();
    pos=pos%len;
    reverse(s.begin(),s.begin()+pos); //ba + cde
    reverse(s.begin()+pos,s.end());//ba + edc
    reverse(s.begin(),s.end());//cdeab
    cout<<s;
}
void rightrotate(string s, int pos)
{
    int len=s.length();
    pos=pos%len;
    reverse(s.begin()+len-pos,s.end()); //abc + ed
    reverse(s.begin(),s.begin()+len-pos);//cba + ed
    reverse(s.begin(),s.end());//deabc
    cout<<s;
}
int main() {
    
    string s="abcde";
    string goal="bcdea";
    cout<<isrotateString(s,goal)<<endl;
    leftrotate(s,2);
    cout<<endl;
    rightrotate(s,2);
    //cout<<s;
    return 0;
}
