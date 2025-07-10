class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        //greedy approach //s[i]>=g[j]
        int gn=g.size();
        int sn=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int gi=0;
        int si=0;
        while(gi<gn && si<sn)
        {
            if(g[gi]<=s[si])
            {
                gi++; //current child greed is satisfied lets move to next child
            }
            si++; //always move to the next cookie whether the current child was satisfied or not
        }
        return gi;
    }
};
