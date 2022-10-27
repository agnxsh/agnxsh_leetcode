class Solution {
public:
    int largestOverlap(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n = a.size();
        vector<int> lena, lenb;
        unordered_map<int,int> c;
        for(int i=0;i<n*n;i++)
        {
            if(a[i/n][i%n]==1)
            {
                lena.push_back(i/n*100+i%n);
            }
        }
        for(int i=0;i<n*n;i++)
        {
            if(b[i/n][i%n]==1)
            {
                lenb.push_back(i/n*100+i%n);
            }
        }
        for ( int i : lena) for(int j : lenb) c[i-j]++;
        int sol = 0;
        for (auto it : c) sol = max(sol,it.second);
        return sol;
        
    }
};