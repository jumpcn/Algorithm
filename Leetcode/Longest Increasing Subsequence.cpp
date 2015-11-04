class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        int dp[nums.size()];
        int ans = -1;
        for(int i = 0; i < nums.size(); i++) {
            dp[i] = 1;
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
