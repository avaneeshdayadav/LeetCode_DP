class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 2)
            return max(nums[0],nums[1]);
        if(nums.size() == 3)
            return max(nums[0],max(nums[1],nums[2]));
        
        
        int dpSize1 = nums.size()-1,dpSize2 = nums.size();
        int memo1[dpSize1],memo2[dpSize2];
        
        memset(memo1,-1,sizeof(memo1));
        memset(memo2,-1,sizeof(memo2));
        
        return max(ans(nums,0,memo1,dpSize1), ans(nums,1,memo2,dpSize2));
        
    }
    
    int ans(vector<int> &nums,int indx, int *memo, int n)
    {
        if(indx >= n)
            return 0;
        
        if(memo[indx] != -1)
            return memo[indx];
        
        memo[indx] = max(nums[indx]+ans(nums,indx+2,memo,n), ans(nums,indx+1,memo,n));
        
        return memo[indx];
    }
    
    
};
