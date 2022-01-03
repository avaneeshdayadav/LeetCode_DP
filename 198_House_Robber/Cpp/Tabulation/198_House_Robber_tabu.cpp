
class Solution {
public:
    int rob(vector<int>& nums) {
        
        int dpSize = nums.size()+2;
        int dp[dpSize];
        memset(dp, -1, sizeof(dp));
        
        dp[dpSize-1] = dp[dpSize-2] = 0;
        
        for(int i=dpSize-3;i>=0;i--)
        {
            dp[i] = max(nums[i]+dp[i+2],dp[i+1]);
        }
        return dp[0];
    }
    
};
