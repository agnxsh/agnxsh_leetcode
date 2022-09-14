class Solution {
public:
    
    int solve(vector<int> &nums, int i, bool pick, vector<vector<int>>&dp)
    {
        if(i>=nums.size()) return pick ? 0:-1e5;
        if(dp[pick][i]!=-1) return dp[pick][i];
        if(pick)
        {
            return dp[pick][i]= max(0,nums[i]+solve(nums,i+1,true,dp));
        }
        return dp[pick][i] = max(solve(nums,i+1,false,dp),nums[i]+solve(nums,i+1,true,dp));
        
    }
    
    int maxSubArray(vector<int>&nums) {
        vector<vector<int>> dp(2,vector<int>(nums.size(),-1))    ;
        return solve(nums,0,false,dp);
    }
};