class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            ans += nums[i];
        }
        if(ans%2 == 1)
            return false;
        else{
            ans = (ans/2);
            vector<vector<bool>> K(nums.size()+1, vector<bool>(ans+1));
            for(int i=0; i<nums.size()+1; i++){
                for(int j=0; j<ans+1; j++){
                    if(j == 0){
                        K[i][j] = true;
                        continue;
                    }
                    if(i == 0){
                        K[i][j] = false;
                        continue;
                    }
                    if(nums[i-1] <= j){
                        K[i][j] = (K[i-1][j] || K[i-1][j-nums[i-1]]);
                    }
                    else K[i][j] = K[i-1][j];
                }
            }
            return K[nums.size()][ans];
        }
    }
};