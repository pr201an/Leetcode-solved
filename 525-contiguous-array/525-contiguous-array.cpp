class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            if(i == 0 && nums[i] == 1)
                continue;
            if(i == 0 && nums[i] == 0){
                nums[0] = -1;
                continue;
            }
            if(nums[i] == 0)
                nums[i] = nums[i-1]-1;
            else
                nums[i] = nums[i-1]+1;
        }
        int ans = 2;
        unordered_map<int, int> ump;
        ump[0] = -1;
        for(int i=0; i<nums.size(); i++){
            if(ump.find(nums[i]) == ump.end())
                ump[nums[i]] = i;
            else
                ans = max(ans, i-ump[nums[i]]);
        }
        vector<int>::iterator it;
        if(ans == 2){
            if(nums[0] == -1 && nums[nums.size()-1] == (0-nums.size()))
                ans = 0;
            else if(nums[0] == 1 && nums[nums.size()-1] == (nums.size()))
                ans = 0;
        }
        return ans;
    }
};