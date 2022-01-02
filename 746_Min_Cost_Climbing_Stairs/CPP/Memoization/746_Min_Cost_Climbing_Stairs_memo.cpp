class Solution {
public:
int ans(vector<int> &cost, int indx, int *dp)
{
    if(indx >= cost.size())
    {
        dp[indx] = 0;
        return 0;
    }

    if(dp[indx] != -1)
        return dp[indx];
        
    
    dp[indx] = min( cost[indx] + ans(cost,indx+1,dp) , cost[indx] + ans(cost,indx+2,dp) );

    return dp[indx];
}


int minCostClimbingStairs(vector<int>& cost) {
        
    int dpSize = cost.size()+2;
    int dp[dpSize];
    
    
    // cout<<"Dp size is "<<dpSize<<endl;
    
    for(int i=0;i<dpSize;i++)
        dp[i] = -1;
    

    dp[0] = ans(cost,0,dp);
    dp[1] = ans(cost,1,dp);
    
    
    return min(dp[0],dp[1]);
    
}

};
