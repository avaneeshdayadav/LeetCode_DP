class Solution {
    
    public int minCostClimbingStairs(int[] cost) {
        
        int dpSize = cost.length+2;
        int dp[] = new int[dpSize];
        Arrays.fill(dp,-1);
        
        
        dp[dpSize-1] = dp[dpSize-2] = 0;
        
        for(int i=dpSize-3;i>=0;i--)
        {
            dp[i] = cost[i] + Math.min(dp[i+1],dp[i+2]);
        }
        return Math.min(dp[0],dp[1]);
    }
    
}
