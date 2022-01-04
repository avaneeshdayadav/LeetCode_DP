class Solution {
    public int rob(int[] nums) {
        
        if(nums.length == 1)
            return nums[0];
        if(nums.length == 2)
            return Math.max(nums[0],nums[1]);
        if(nums.length == 3)
            return Math.max(nums[0],Math.max(nums[1],nums[2]));
        
        
        int memo1[] = new int[nums.length-1];
        Arrays.fill(memo1,-1);
             
        int memo2[] = new int[nums.length];
        Arrays.fill(memo2,-1);
        
        return Math.max(ans(nums,0,memo1,nums.length-1),ans(nums,1,memo2,nums.length));
    }
    
   public int ans(int[] nums,int indx,int memo[],int n)
    {
        if(indx >= n)
            return 0;
        
        if(memo[indx] != -1)
            return memo[indx];
        
        memo[indx] = Math.max(nums[indx]+ans(nums,indx+2,memo,n), ans(nums,indx+1,memo,n));
        return memo[indx];
    }
}
