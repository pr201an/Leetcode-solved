class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int ans = INT_MIN;
        nums.push_back(0);
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 1)
                count++;
            if(nums[i] == 0){
                ans = max(ans,count);
                count = 0;
            }
        }
        return ans;
    }
};