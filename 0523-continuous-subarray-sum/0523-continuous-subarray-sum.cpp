class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] = -1;
        nums[0] = nums[0] % k;
        for(int i=1; i<nums.size(); i++){
            nums[i] = (nums[i-1]+nums[i]) % k;
        }
        bool ans = false;
        for(int i=0; i<nums.size(); i++){
            if(map.find(nums[i]) != map.end()){
                if(i - map[nums[i]] > 1){
                    ans = true;
                    break;
                }
            }
            else map[nums[i]] = i;
        }
        return ans;
    }
};