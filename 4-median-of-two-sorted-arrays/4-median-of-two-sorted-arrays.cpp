#include <bits/stdc++.h>
class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        if(nums2.size()<nums1.size()) return findMedianSortedArrays(nums2,nums1);
        int n1 = nums1.size();
        int n2 = nums2.size();
        int low = 0, high = n1;
        int left1, left2, right1, right2, cut1,cut2;
        while(low<=high)
        {
             cut1 = (low +high)/2.0;
             cut2 = (n1+n2+1)/2 -cut1;
            
            left1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
            left2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];
            
            right1 =cut1==n1?INT_MAX : nums1[cut1];
            right2 =cut2==n2?INT_MAX : nums2[cut2];
            
            if(left1 <= right2 && left2<=right1)
            {
                if((n1+n2)%2!=0) { return max(left1,left2);}
                   
                   
                else {return (max(left1, left2) + min(right1,right2)) / 2.0; }
                    
                
            }
            else if(left1>right2)
            {
                high = cut1-1;
                
            }
            else{
                low=cut1+1;
            }
        }
        return 0.0;
    }
};