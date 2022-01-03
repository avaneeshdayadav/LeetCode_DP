
class Solution {
    public int rob(int[] nums) {
        
        int memo[] = new int[nums.length];
        Arrays.fill(memo,-1);
        
        return ans(nums,0,memo);
    }
    
    public int ans(int[] nums,int indx,int memo[])
    {
        if(indx >= nums.length)
            return 0;
        
        if(memo[indx] != -1)
            return memo[indx];
        
        memo[indx] = Math.max(nums[indx]+ans(nums,indx+2,memo), ans(nums,indx+1,memo));
        return memo[indx];
    }
}
