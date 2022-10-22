class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128,0);
        for(auto c: t) map[c]++;
        int count = t.size();
        int begin=0, end=0, d=INT_MAX, head=0;
        while(end<s.size())
        {
            if(map[s[end++]]-->0)
            {
             count--;
            }
            while(count==0)
            {
                if(end-begin<d)
                {
                    d=end-(head=begin);
                }
                if(map[s[begin++]]++==0) count++;
                
            }
        }
        return d==INT_MAX?"":s.substr(head,d);
    }
};