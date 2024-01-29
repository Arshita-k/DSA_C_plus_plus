#include <iostream>
#include <fstream>
// ifstream to read from a file 
// ofstream to create/open and write to a file
using namespace std;
int main()
{
    fstream my_file("test.txt",ios::out);
    if(!my_file) // !my_file.is_open() or my_file.fail()
    {
        cout<<"Error opening the file"<<endl;
        return 1;
    }
    my_file<<"Hello! how are you?"<<endl;
    my_file<<"My name is Arshita"<<endl;
    my_file.close();

    string line;
    my_file.open("test.txt",ios::in);
     if(my_file) // !my_file.is_open() or my_file.fail()
    {
        while(!my_file.eof())
        {
            getline(my_file,line);
            cout<<line<<endl;
        }
        my_file.close();
    }
    else      
    {
        cout<<"Error opening the file"<<endl;
        return 1;
    }
    return 0;
}




 
