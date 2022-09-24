class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int maxi=A[0]+0;
        int ans=-1;
        int n=A.size();
        for(int i=1;i<n;i++)
        {
            ans=max(ans,maxi+A[i]-i);
            maxi=max(maxi,A[i]+i);
            //stores the maximum value of i + i into the dp table
        }
        return ans;
        
    }
};