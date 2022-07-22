class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans=0;
        int current=0;
        unordered_set<int> set;
        int i=0;
        int j=0;
        for(i=0,j=0;j<nums.size();j++)
        {
            while(set.find(nums[j])!=set.end())
            {
                //until the nums[j]th position of set is the last element of the set
                set.erase(nums[i]);
                current-=nums[i];
                i++;
             }
            set.insert(nums[j]);
            current+=nums[j];
            ans=max(ans,current);
            
        }
        return ans;    }
};