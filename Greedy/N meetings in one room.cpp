struct meeting {
        int startTime, endTime, pos;
    };
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    bool static compare(struct meeting m1, meeting m2)
    {
        return m1.endTime<m2.endTime;
    }
    int maxMeetings(vector<int>& start, vector<int>& end) {
        vector<int>res;
        int n=start.size();
        vector<meeting>meets(n);
        for(int i=0;i<n;i++)
        {
            meets[i].startTime=start[i];
            meets[i].endTime=end[i];
            meets[i].pos=i+1;
        }
        sort(meets.begin(),meets.end(),compare);
        
        int currTime=-1;
        for(int i=0;i<n;i++)
        {
            if(meets[i].startTime>currTime)
            {
                currTime=meets[i].endTime;
                res.push_back(meets[i].pos);
            }
        }
        sort(res.begin(),res.end());
        return res.size();
        
    }
};
