class Solution {
    typedef pair<long,long> cp;
public:
    long long minimumWeight(int n, vector<vector<int>>& E, int a, int b, int dest) {
        vector<vector<cp>> G(n), R(n);
        //denotes the forward and the reversed graph
        for(auto &e: E)
        {
            long u = e[0], v=e[1], w=e[2];
            G[u].emplace_back(v,w);
            R[v].emplace_back(u,w);
            
        }
        
        vector<long> da(n,LONG_MAX), db(n,LONG_MAX), dd(n,LONG_MAX);
        auto solve = [&](vector<vector<cp>> &G, int a, vector<long> &dist)
        {
            priority_queue<cp,vector<cp>,greater<cp>> pq;
            dist[a]=0;
            pq.emplace(0,a);
            while(pq.size())
            {
                auto[cost,u] = pq.top();
                pq.pop();
                if(cost>dist[u]) continue;
                for(auto &[v,c] : G[u])
                {
                    if(dist[v]>dist[u]+c)
                    {
                        dist[v]=dist[u]+c;
                        pq.emplace(dist[v],v);
                    }
                }
            }
            
        };
        solve(G,a,da);
        solve(G,b,db);
        solve(R,dest,dd);
        long ans = LONG_MAX;
        for(int i=0;i<n;i++)
        {
            if(da[i]==LONG_MAX || db[i]==LONG_MAX || dd[i]==LONG_MAX) continue;
            ans = min(ans,da[i]+db[i]+dd[i]);
        }
        return ans == LONG_MAX ? -1:ans;
    }
};