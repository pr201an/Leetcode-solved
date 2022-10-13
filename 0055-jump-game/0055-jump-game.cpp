class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n , false);
        dp[0] = true;
        for(int i=0; i<nums.size(); i++){
            if(dp[i] == true){
                int temp = nums[i];
                for(int j=1; j<=temp and i+j<n; j++){
                    dp[i+j] = true;
                }
            }
            else continue;
        }
        return dp[n-1];
    }
};