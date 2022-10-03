class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res=0; 
        int maxtime=0;
        int sumtime=0;
        int n = colors.size();
        for(int i=0;i<n;i++)
        {
            if(i>0 && colors[i]!=colors[i-1])
            {
                res+=sumtime - maxtime;
                sumtime = maxtime=0;
                //resetting the values
                
            }
            sumtime+=neededTime[i];
            maxtime=max(maxtime,neededTime[i]);
        }
        res+=sumtime - maxtime;
        return res;
    }
};