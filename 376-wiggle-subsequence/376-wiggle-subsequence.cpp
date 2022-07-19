class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int x= nums.size();
        if(x<2)
        {
            return x;
        }
        int prev = nums[1]-nums[0];
        int count = prev != 0 ? 2 :1;
        for(int i=2;i<x;i++)
        {
         
            int diff=nums[i]-nums[i-1];
            if(diff<0 && prev>=0 || diff>0 && prev<=0)
            {
                count++;
                prev=diff;
            }
           
        }
        return count;
    }
};