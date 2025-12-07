//C++ Solution
// https://leetcode.com/problems/count-partitions-with-max-min-difference-at-most-k/description/

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;

        multiset<int> currentWindow;
      
        int n = nums.size();

        vector<int> dp(n + 1, 0);
      
        vector<int> prefixSum(n + 1, 0);
     
        dp[0] = 1;
        prefixSum[0] = 1;
  
        int leftPtr = 1;
      
        for (int rightPtr = 1; rightPtr <= n; ++rightPtr) {

            int currentElement = nums[rightPtr - 1];
            currentWindow.insert(currentElement);
        
            while (*currentWindow.rbegin() - *currentWindow.begin() > k) {

                currentWindow.erase(currentWindow.find(nums[leftPtr - 1]));
                ++leftPtr;
            }
        
            int waysFromValidStarts = prefixSum[rightPtr - 1] - 
                                      (leftPtr >= 2 ? prefixSum[leftPtr - 2] : 0);
            dp[rightPtr] = (waysFromValidStarts + MOD) % MOD;
          
            prefixSum[rightPtr] = (prefixSum[rightPtr - 1] + dp[rightPtr]) % MOD;
        }
    
        return dp[n];
    }
};
