class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        for(int i=1; i<nums.size(); i++){
            nums[i] += nums[i-1];
        }
        unordered_map<int, int> map;
        map[0] = 1;
        int count =0;
        for(int i=0; i<nums.size(); i++){
            if(map[nums[i]%k] != 0){
                count += map[nums[i]%k];
                cout << count << " " << i << endl; 
            }
            if(map[(nums[i]%k)+k] != 0){
                count += map[(nums[i]%k)+k];
                cout << count << " " << i << endl; 
            }
            if(nums[i] < 0)
                map[(nums[i]%k) + k]++;
            else
                map[nums[i]%k]++;
        }
        return count;
    }
};