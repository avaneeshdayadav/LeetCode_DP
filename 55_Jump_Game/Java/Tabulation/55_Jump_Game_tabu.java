class Solution {
    public boolean canJump(int[] nums) {
        Boolean dp[] = new Boolean[nums.length];
        dp[nums.length-1]=Boolean.TRUE;
        int need=1;
        
        for(int i=nums.length-2;i>=0;i--)
        {
            if(nums[i]>=need)
            {
                dp[i] = Boolean.TRUE;
                need = 1;
            }
            else
            {
                dp[i]=Boolean.FALSE;
                need++;
            }  
        }
        
        return dp[0];
        
    }
    
        
}
