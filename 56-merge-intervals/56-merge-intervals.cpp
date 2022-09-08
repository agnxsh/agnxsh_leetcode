class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int length = intervals.size();
        if(length ==0) return res;
        sort(intervals.begin(),intervals.end());
        
        res.push_back(intervals[0]);
        for (int i=1;i<length;i++)
        {
            vector<int> Vec = res.back();
            if(intervals[i][0]>Vec[1])
            {
                res.push_back(intervals[i]);
                
            }
            else
            {
                res.back()[1]=max(res.back()[1],intervals[i][1]);
            }
        }
        return res;
    }
};