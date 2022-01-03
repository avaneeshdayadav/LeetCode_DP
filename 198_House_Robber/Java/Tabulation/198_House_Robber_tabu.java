
class Solution {
    public int rob(int[] nums) {
        
        int dpSize = nums.length+2;
        int dp[] = new int[dpSize];
        
        Arrays.fill(dp,-1);
        
        dp[dpSize-1] = dp[dpSize-2] = 0;
        
        for(int i=dpSize-3;i>=0;i--)
            dp[i] = Math.max(nums[i]+dp[i+2], dp[i+1]);
        
        return dp[0];
    }
    
    
}
