class Solution {
public:
    
    int findParent(int n, vector<int> p)
    {
        if(n==p[n])
        {
            return n;
        }
        
        return findParent(p[n],p);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        vector<int> parent(1001,0);
        for(int i=0;i<parent.size();i++)
        {
            parent[i]=i;        
            //storing every current node's parent as itself
        }
        vector<int> res;
        for(auto v : edges)
        {
            int n1= v[0], n2=v[1];
            int p1=findParent(n1, parent);
            int p2=findParent(n2, parent);
            if(p1==p2)
            {
                res=v;
            }
            parent[p1]=p2;
            
        }
        return res;
        
    }
};