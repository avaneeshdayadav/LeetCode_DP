class Solution {
public:
    int rob(vector<int>& nums) {
        
        int memo[nums.size()];
        memset(memo, -1, sizeof(memo));
        return ans(nums,0,memo);
    }
    
    int ans(vector<int> &nums, int indx, int *memo)
    {
        if(indx >= nums.size())
            return 0;
        
        if(memo[indx] != -1)
            return memo[indx];
        
        memo[indx] = max(nums[indx]+ans(nums,indx+2,memo), ans(nums,indx+1,memo));
        return memo[indx];
    }
};
