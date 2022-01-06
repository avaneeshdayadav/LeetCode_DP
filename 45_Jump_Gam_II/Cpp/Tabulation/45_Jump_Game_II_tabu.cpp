// Greedy solution is much better than dp here.

class Solution {
    public:
    int jump(vector<int>& nums) {
     
        int dp[nums.size()];
        dp[nums.size()-1] = 0;
        
        int need = 1;
    
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i] < need)
            {
                need++;
                dp[i] = 10000;
            }
            else
            {
                int j = nums[i] + i;
                if(j>nums.size()-1)
                    j = nums.size()-1;
                int min = dp[j];

                for(;j>i;j--)
                {
                    if(dp[j] < min)
                        min = dp[j];
                }
                dp[i] = min+1;
                need=1;
            }
            
        }
        return dp[0];
    }
};
