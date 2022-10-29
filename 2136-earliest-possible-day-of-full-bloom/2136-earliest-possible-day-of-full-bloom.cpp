class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n =plantTime.size();
        vector<pair<int,int>> store(n);
        
        for(int i=0;i<plantTime.size();i++)
        {
            store[i].first = -growTime[i];
            store[i].second = plantTime[i];
            
        }
        sort(store.begin(),store.end());
        int tot=0;
        int cur=0;
        
        for(int i=0;i<store.size();i++)
        {
            tot = max(tot,cur+(store[i].second-store[i].first));
            cur += store[i].second;
        }
        return tot;
    }
};