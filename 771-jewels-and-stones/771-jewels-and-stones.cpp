class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map<char,int> mp;
        int n=jewels.length();
        for(int i=0;i<n;i++)
        {
            mp[jewels[i]]=1;
        }
        int total=0;
        int nu = stones.length();
        for (int i=0;i<nu;i++)
        {
            if(mp.find(stones[i])!=mp.end())
            {
                total++;
            }
        }
        return total;
    }
};