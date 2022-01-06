// Slow soln with O(n^2) complexity.

class Solution {
    public:
    int jump(vector<int>& nums) {
     
        int memo[nums.size()];
        memo[nums.size()-1]=0;
        for(int i=0;i<nums.size()-1;i++)
            memo[i] = 10000;
        
        return ans(nums,0,memo);
    }
    
    int ans(vector<int>& nums,int indx,int *memo)
    {
        if(indx >= nums.size()-1)
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
};
