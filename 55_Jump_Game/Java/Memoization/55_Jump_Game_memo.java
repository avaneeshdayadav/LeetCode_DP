class Solution {
    public boolean canJump(int[] nums) {
        int memo[] = new int[nums.length];
        Arrays.fill(memo,-1);
        return ans(nums,0,memo);  
    }
    
    public boolean ans(int[] nums,int indx,int[] memo)
    {
        if(indx >= nums.length-1)
            return true;
            
        if(nums[indx] == 0)
        {
            memo[indx] = 0;
            return false;
        }
            
        
        if(memo[indx]!=-1)
        {
            return memo[indx] == 1;
        }
            
        
        for(int i=1;i<=nums[indx];i++)
        {
            if(ans(nums,indx+i,memo))
            {
                memo[indx] = 1;
                return true;
            }
                
        }
        
        memo[indx] = 0;
        return false;
    }
}
