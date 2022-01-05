// NOT VERY EFFICIENT
// Time wastage in calculating max of the given vector.
// Freq count array takes extra space.

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        // A max variable that stores maximum value element in given vector.
        int max = -1;
        for(int i=0;i<nums.size();i++)
        {
            if(max < nums[i])
                max = nums[i]; 
        }
        
        // Create a freq count array of length max+1 to store freq of no's upto max.
        int newNums[max+1];
        
        // Create a memoization array to remember previously calculated values of length 2 greater than freq count array.
        int memo[max+3];
        
        // Initialize memoization array to all -1 value.
        memset(memo,-1,sizeof(memo));
        
        
        // Make last two values of memoization array as 0.
        memo[max+1]=memo[max+2]=0;
        
        // Initialize freq count array to all zero.
        memset(newNums,0,sizeof(newNums));
        
        
        // Count freq of each element and store in freq count array.
        for(int i=0;i<nums.size();i++)
            newNums[nums[i]]++;
        
        // Robber House reccursive func called.
        return ans(newNums,0,max+1,memo);
            
    }
    
    int ans(int *newNums,int indx,int n,int *memo)
    {
        if(indx >= n)
            return 0;
        
        if(memo[indx]!=-1)
            return memo[indx];
        
        memo[indx] =  max(newNums[indx]*indx + ans(newNums,indx+2,n,memo),ans(newNums,indx+1,n,memo));
        
        return memo[indx];
    }
};
