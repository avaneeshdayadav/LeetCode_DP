
class Solution {
public:

int minCostClimbingStairs(vector<int>& cost) {
    
    int dpSize = cost.size()+2;
    int dp[dpSize];
    dp[dpSize-1] = dp[dpSize-2] = 0;
    
    for(int i=dpSize-3;i>=0;i--)
    {
        dp[i] = cost[i] + min(dp[i+1],dp[i+2]);
    }
    
    return min(dp[0],dp[1]);
    
}

};
