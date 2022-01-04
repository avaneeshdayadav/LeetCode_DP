class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 2)
            return max(nums[0],nums[1]);
        if(nums.size() == 3)
            return max(nums[0],max(nums[1],nums[2]));
            
        int dpSize1 = nums.size()+1, dpSize2 = nums.size()+2;
        int dp1[dpSize1],dp2[dpSize2];
        
        dp1[dpSize1-1] = dp1[dpSize1-2] = 0;
        dp2[dpSize2-1] = dp2[dpSize2-2] = 0;
        
        for(int i=dpSize1-3;i>=0;i--)
            dp1[i] = max(nums[i]+dp1[i+2],dp1[i+1]);
        
        for(int i=dpSize2-3;i>=1;i--)
            dp2[i] = max(nums[i]+dp2[i+2],dp2[i+1]);
        
        return max(dp1[0],dp2[1]);
    }
};
