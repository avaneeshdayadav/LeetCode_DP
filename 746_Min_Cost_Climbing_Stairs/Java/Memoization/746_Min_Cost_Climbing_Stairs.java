class Solution {
    public int minCostClimbingStairs(int[] cost) {
        
        int dp[] = new int[cost.length+2];
        Arrays.fill(dp,-1);
        
        return Math.min(fun(cost,0,dp) , fun(cost,1,dp));
    }
    
    public int fun(int[] cost, int indx, int[] dp)
    {
        //System.out.println("Hello");
        
        if(indx >= cost.length)
        {
            dp[indx] = 0;
            return 0;
        }
        
        if(dp[indx] != -1)
            return dp[indx];
        
        dp[indx] = cost[indx] + Math.min(fun(cost,indx+1,dp), fun(cost,indx+2,dp));
        
        return dp[indx];
    }
    
}
