// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <stack>

using namespace std;
string decodeString(string s)
{
    stack<char> st;
    for (char ch : s) 
    {
        //untill we get a close bracket
        if (ch != ']') 
        {
            st.push(ch);
        } 
        else 
        {
            //Extract encoded string 'like in 3[a2[c -> c first extracted
            //second extraction 3[acc -> acc 
            string temp;
            while (!st.empty() && st.top() != '[') 
            {
                temp = st.top() + temp; //make the string
                st.pop();
            }

            // Step 2: Pop the '[' opening bracket 
            st.pop();

            // Step 3: Extract number
            string numStr;
            while (!st.empty() && isdigit(st.top())) {
                numStr = st.top() + numStr;
                st.pop();
            }
            int k = stoi(numStr); //convert string to number

            // Step 4: Push expanded string k times
            while (k--) 
            {
                for (char c : temp) 
                {
                    st.push(c);
                }
                //3[acc stack 1st decode
                //accaccacc 2nd decode
            }
            //move to next decode if stack not empty till now
        }
    }

    // Step 5: Build final result
    string res;
    while (!st.empty()) {
        res = st.top() + res;
        st.pop();
    }
    //final string accaccacc
    return res;
}
int main() {
   
    string s="3[a2[c]]";
    cout<<decodeString(s);
    return 0;
}
