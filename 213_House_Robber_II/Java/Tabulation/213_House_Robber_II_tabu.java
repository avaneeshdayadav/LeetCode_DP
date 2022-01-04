class Solution {
    public int rob(int[] nums) {
        
        if(nums.length == 1)
            return nums[0];
        if(nums.length == 2)
            return Math.max(nums[0],nums[1]);
        if(nums.length == 3)
            return Math.max(nums[0],Math.max(nums[1],nums[2]));
        
        int dpSize1 = nums.length+1, dpSize2 = nums.length+2;
        int dp1[] = new int[dpSize1];
        int dp2[] = new int[dpSize2];
        
        Arrays.fill(dp1,-1);
        Arrays.fill(dp2,-1);
        
        dp1[dpSize1-1] = dp1[dpSize1-2] = 0;
        dp2[dpSize2-1] = dp2[dpSize2-2] = 0;
        
        
        for(int i=dpSize1-3;i>=0;i--)
        {
            System.out.println(i);
            dp1[i] = Math.max(nums[i]+dp1[i+2],dp1[i+1]);
        }
            
        
        for(int i=dpSize2-3;i>=1;i--)
            dp2[i] = Math.max(nums[i]+dp2[i+2],dp2[i+1]);
        
        return Math.max(dp1[0],dp2[1]);
    }
    
  
}
