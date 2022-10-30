class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int lo = 0, hi = 1;
        while(hi < nums.size()){
            if(nums[hi] == nums[lo]){
                while(hi < nums.size() && nums[hi] == nums[lo]){
                    nums[hi] = 101;
                    hi++;
                }
            }
            else{
                lo = hi;
                hi++;
            }
        }
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 101)
                ans++;
        }
        return ans;
    }
};