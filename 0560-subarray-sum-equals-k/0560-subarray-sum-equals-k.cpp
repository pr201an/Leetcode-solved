class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] = 1;
        int ans = 0;
        for(int i=1; i<nums.size(); i++){
            nums[i] += nums[i-1];
        }
        for(int i=0; i<nums.size(); i++){
            if(map.find(nums[i] - k) != map.end())
                ans += map[nums[i] - k];
            map[nums[i]]++;
        }
        return ans;
    }
};