// Greedy soln is much better here than dp

class Solution {
    public int jump(int[] nums) {
     
        int dp[] = new int[nums.length];
        dp[nums.length-1] = 0;
        
        int need = 1;
        // int minIndx = nums.length-1;
        for(int i=nums.length-2;i>=0;i--)
        {
            if(nums[i] < need)
            {
                need++;
                dp[i] = 10000;
                
            }
            else
            {
                int j = nums[i] + i;
                if(j>nums.length-1)
                    j = nums.length-1;
                // if(j>minIndx)
                //     j=minIndx;
                int min = dp[j];

                for(;j>i;j--)
                {
                    if(dp[j] < min)
                    {
                        // minIndx = j;
                        min = dp[j];
                    }
                        
                }

                dp[i] = min+1;
                need=1;
                
            }
            
        }
        
        for(int i=0;i<dp.length;i++)
            System.out.println(dp[i]);
        return dp[0];
    }
}
