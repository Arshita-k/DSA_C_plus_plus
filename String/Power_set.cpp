	vector<string> AllPossibleStrings(string s){
		   
		   int n=s.length();
		   vector<string>answer;
		   for(int i=0;i<(1<<n);i++)
		   {
		        string sub="";
		        for(int j=0;j<n;j++)
		        {
		            if(i&(1<<j))
		            {
		                sub=sub+s[j];
		            }
		        }
		        if(sub.length()>0)
		        {
		            answer.push_back(sub);
		        }
		   }
		   sort(answer.begin(),answer.end());
		   return answer;
		}
