class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(int i=1; i<nums.size(); i++){
            nums[i] += nums[i-1];
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i] < 0)
                nums[i] = (k - abs(nums[i]%k))%k;
            else nums[i] = nums[i]%k;
        }
        for(int i=0; i<nums.size(); i++){
            cout << nums[i] << " ";
        }
        cout << endl;
        map[0] = 1;
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            if(map.find(nums[i]) != map.end()){
                ans += map[nums[i]];
            }
            map[nums[i]]++;
        }
        return ans;
    }
};