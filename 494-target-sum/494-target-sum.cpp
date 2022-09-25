class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0, zero=0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(nums[i] == 0)
                zero++;
        }
        if((target+sum) %2 != 0  || target > sum || (target+sum) < 0)
            return 0;
        int lastnum = (sum+target)/2;
        vector< vector<int>> K(nums.size()+1, vector<int>(lastnum+1));
        for(int i=0; i<nums.size()+1; i++){
            for(int j=0; j<lastnum+1; j++){
                if(j == 0){
                    K[i][j] = 1;
                    continue;
                }
                if(i == 0){
                    K[i][j] = 0;
                    continue;
                }
                if(nums[i-1] <= j)
                    K[i][j] = K[i-1][j] + K[i-1][j-nums[i-1]];
                if(nums[i-1] > j || nums[i-1] == 0) 
                    K[i][j] = K[i-1][j];
            }
        }
        return pow(2,zero)*K[nums.size()][lastnum];
    }
};