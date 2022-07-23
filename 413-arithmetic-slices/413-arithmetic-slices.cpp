class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int current=0;
        int total=0;
        for(int i=2;i<nums.size();i++)
        {
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2])
            {
                current++;
                total = total+current;
            }
            else 
            {
                current=0;
            }
        }
        return total;
    }
    
};