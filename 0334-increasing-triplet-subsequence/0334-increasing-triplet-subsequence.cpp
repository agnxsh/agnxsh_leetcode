class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int c1 = INT_MAX;
        int c2 = INT_MAX;
        for(int x : nums)
        {
            if(x<=c1)
            {
                c1 =x;
            }
            //checking if c1 is the min or not
            else if(x<=c2)
            {
                //x is > c1 and <=c2
                c2=x;
            }
            //x is eventually the third element
            else {return true;}
        }
        return false;

            
    }
};