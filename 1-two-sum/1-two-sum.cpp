class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int smol = 0, big = nums.size()-1;
        vector<pair<int, int>> v;
        for(int i=0; i<nums.size(); i++){
            v.push_back (make_pair(nums[i], i));
        }
        sort(v.begin(),v.end());
        vector<int> ans;
        for(int j=0;j<nums.size();j++){
            if(v[smol].first+ v[big].first > target)
                big--;
            if(v[smol].first+ v[big].first < target)
                smol++;
            if(v[smol].first+ v[big].first == target){
                ans.push_back(v[smol].second);
                ans.push_back(v[big].second);
                break;
            }
        }
        return ans;
    }
};