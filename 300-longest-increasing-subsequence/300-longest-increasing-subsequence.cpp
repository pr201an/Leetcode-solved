class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v(nums.size());
        v[0] = 1;
        for(int i=1;i<nums.size();i++){
            int tempans = 0;
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i])
                    tempans = max(tempans, v[j]);
            }
            v[i] = tempans + 1;
        }
        int ans;
        for(int i=0;i<v.size();i++){
            ans = max(ans, v[i]);
        }
        return ans;
    }
};