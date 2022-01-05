// Memoization Very slow with 280ms runtime.

class Solution {
    public int jump(int[] nums) {
        int memo[] = new int[nums.length];
        memo[nums.length-1]=0;
        Arrays.fill(memo,10000);

        return ans(nums,0,memo);
    }
    
    public int ans(int[] nums,int indx,int[] memo)
    {
        if(indx >= nums.length-1)
             return 0;
            
        if(nums[indx] == 0)
        {
            memo[indx] = 10000;
            return 10000;
        }
  
        if(memo[indx]!=10000)
        {
            return memo[indx];
        }
            
        int minSteps=10000;
        int temp;
        for(int i=1;i<=nums[indx];i++)
        {
            temp = 1+ans(nums,indx+i,memo);
            if(temp<minSteps)
                minSteps = temp;
        }
        
        memo[indx] = minSteps;
        return minSteps;
    }
}
