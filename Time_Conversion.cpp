#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    
    int n=s.size()-1;
    string Time=s.substr(n-1,2);
    
    string answer;
    cout<<Time;
    if(Time=="AM")
    {
        if(s.substr(0,2)=="12")
        {
            //new day mid night
            s.replace(s.begin(),s.begin()+2,"00");
        }
    }
    else if(Time=="PM")
    {
        if(s.substr(0,2)=="12")
        {
            //noon time 
            return s.substr(0,n-1);
        }
        int hr=stoi(s.substr(0,2));
        hr=hr+12;
        s.replace(s.begin(),s.begin()+2,to_string(hr));
    }
    return s.substr(0,n-1);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
