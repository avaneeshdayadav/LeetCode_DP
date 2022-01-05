// Extra space wasted for count freq (newNums) array.
// Extra time wasted for calculating maxElem of given error.

class Solution {
public:

  int deleteAndEarn(vector<int>& nums)
  {

      // A max variable that stores maximum value element in given vector.
      int maxElem = -1;
      for(int i=0;i<nums.size();i++)
      {
          if(maxElem < nums[i])
              maxElem = nums[i]; 
      }

      // Create a freq count array of length maxElem+1 to store freq of no's upto maxElem.
      int newNums[maxElem+1];

      // Initialize freq count array to all zero.
      memset(newNums,0,sizeof(newNums));

      // Count freq of each element and store in freq count array.
      for(int i=0;i<nums.size();i++)
          newNums[nums[i]]++;

      int dp[maxElem+3];
      dp[maxElem+2] = dp[maxElem+1] = 0;

      for(int i = maxElem;i>=0;i--)
      {
          dp[i] = max(newNums[i]*i+dp[i+2],dp[i+1]);
      }

      return dp[0];
  }
    
};
