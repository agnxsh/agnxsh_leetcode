class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n=s.size();
        vector<int> total(n);
        if(s[0]=='*') total[0]=1;
        for(int i=1;i<n;i++)
        {
            if(s[i]=='*') total[i]=total[i-1]+1;
            //add one to the previous value
            else total[i]=total[i-1];
        }
        
        vector<int> left(n), right(n);
        //counts the number of candles from left to right
        if(s[0]=='|')left[0]=0;
        else left[0]=-1;
        for(int i=1;i<n;i++)
        {
            if(s[i]!='*') left[i]=i;
            else left[i]=left[i-1];
        }
        
        if(s[n-1]=='|')right[n-1]=n-1;
        else right[n-1]=-1;
        for(int i=n-2;i>=0;i--)
        {
            if(s[i]=='|')right[i]=i;
            else right[i]=right[i+1];
        }
        
        int q;
        q=queries.size();
        
        vector<int> ans;
        for(auto i: queries)
        {
            int l=right[i[0]];
            int r=left[i[1]];
            if(l==-1 || r==-1 || l>=r)
            {
                ans.push_back(0);
                continue;
            }
            ans.push_back(total[r]-total[l]);                
        }
        return ans;
        
    }
};