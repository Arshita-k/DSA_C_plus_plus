class Solution {
public:
    bool checkValidString(string s) {
        
        int openCount=0,closeCount=0;
        int n=s.length()-1;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(' || s[i]=='*')
            {
                openCount++;
            }
            else openCount--;

            if(s[n-i]==')' || s[n-i]=='*')
            {
                closeCount++;
            }
            else closeCount--;

            if(openCount<0 || closeCount<0)
                return false;
        }
        return true;
    }
};



