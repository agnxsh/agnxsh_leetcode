class Solution {
public:
   int ans = 0;
    void solve(vector<int>& v, vector<string>& arr, int i, string s, int status){
        if(i < 0) { 
            ans = max(ans, (int)s.size());
        }else{
            solve(v, arr, i-1, s, status);
            if( (v[i] != INT_MAX ) && ( (v[i] + status) == (v[i] | status)) ){ 
                solve(v, arr, i-1, s+arr[i], status  | v[i]);
            }
        }
    }
    
    int maxLength(vector<string>& arr) {
        vector<int> v(arr.size());
        for(int i= 0; i < arr.size(); ++i){
            for(auto c: arr[i]) {
                if((v[i] >> (c - 'a'))& 1){ //if already bit is set, then set value to INT_MAX
                    v[i] = INT_MAX;
                }else{                      // if not set, then set it to 1
                    v[i] = v[i] | (1 << (c - 'a'));
                }
            }
        }
        string s = "";
        solve(v, arr, arr.size()-1, s, 0);
        return ans;
    }
};