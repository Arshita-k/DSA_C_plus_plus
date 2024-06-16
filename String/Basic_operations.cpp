#include <bits/stdc++.h>
using namespace std;

#define MAX 6 
/*string class stores the characters as a sequence of bytes with the 
functionality of allowing access to the single-byte character.*/

//input--push_back, pop_back, getline
//capacity, resize, length, shrink_to_fit
int main()
{
    string str="practice makes a man perfec";
    cout<<"The initial string is : ";
    cout<<str<<endl;
    //PUSH_BACK
    str.push_back('t');
    cout<<"The string after push_back operation is : ";
    cout<<str<<endl;
    //POP_BACK
    str.pop_back();
    str.pop_back();
    cout<<"The string after two pop_back operation call is : ";
    cout<<str<<endl;
    char str2[MAX];
    string str1;
    //GETLINE  //istream& getline(istream& is, string& str, char delim);
    cout<<"Enter new string2 : ";
    getline(cin,str1); //bydefault newline (\n) character is delimitation charater
    cout<<"Enter new string3 : ";
    cin.getline(str2,MAX);
    cout<<"The 2nd string is : ";
    cout<<str1<<endl;
    cout<<"The 3rd string is : ";
    cout<<str2<<endl;

    // using swap() to swap string content 
    str.swap(str1); 
    cout << "The 1st string after swapping is : "; 
    cout << str << endl; 
    cout << "The 2nd string after swapping is : "; 
    cout << str1 << endl; 
  
    cout << "The capacity of string is : "; 
    cout << str.capacity() << endl; 

    str.resize(8);
    cout << "The string and its length after resize operation is : "; 
    cout << str <<", "<<str.length()<<endl; //str.size()

    cout << "The capacity of string now is still same : "; 
    cout << str.capacity() << endl;

    str.shrink_to_fit();
    cout << "The new capacity after shrinking is : "; 
    cout << str.capacity() << endl;
    return 0;
}
/* OUTPUT
The initial string is : practice makes a man perfec
The string after push_back operation is : practice makes a man perfect
The string after two pop_back operation call is : practice makes a man perfe
Enter new string2 : My name is Arshita
Enter new string3 : Hello
The 2nd string is : My name is Arshita
The 3rd string is : Hello
The 1st string after swapping is : My name is Arshita
The 2nd string after swapping is : practice makes a man perfe
The capacity of string is : 30
The string and its length after resize operation is : My name , 8
The capacity of string now is still same : 30
The new capacity after shrinking is : 15
*/
