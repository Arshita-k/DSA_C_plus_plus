// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
  
    // TAKE INPUT
    string line;
    cout<<"Enter string: ";
    getline(cin,line);
    cout<<"Input string is : "<<line<<endl;
    cout<<"index of substring 'my' in the input string: "<<line.find("my")<<endl;
    
    
    
    
    //SPLIT STRING INTO WORDS AND PUSH INTO A ARRAY
    stringstream ss(line);
    string word;
    vector<string>arr;
    while(ss>>word)
    {
        cout<<word<<endl;
        arr.push_back(word);
    }   
    cout<<"First element of the array"<<arr[0]<<endl;
    
    
    
    
    
    //REMOVE All occurrence of a CHARACTER IN A STRING
    line.erase(remove(line.begin(), line.end(), 'm'), line.end());
    // remove returns an iterator pointing to the new logical end of the string after removing the specified character 
        //string& erase(size_t pos = 0, size_t count = npos);
    cout << "String after removing character 'm': " << line << endl;

    
    
    
    //REMOVE CHARACTERS Based on a condition
    // Set of characters to remove
    unordered_set<char> charsToRemove = {'e', 'l',};
    // Use remove_if with a lambda
    line.erase(remove_if(line.begin(), line.end(), [&](char c) 
    {
        return charsToRemove.count(c); 
        // returns true if c is in the set
    }), line.end());
    cout << "String after removing characters 'e' and 'l': " << line << endl;
    //line.erase(remove_if(line.begin(), line.end(), ::isdigit), line.end());
    return 0;
}
