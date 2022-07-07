class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int start = 0, end = 1, count = 1;
        while(end < nums.size()){
            if(nums[end] == nums[start] && count < 2){
                count++;
                end++;
                continue;
            }
            if(nums[end] == nums[start] && count >=2){
                while(end < nums.size() && nums[end] == nums[start]){
                    nums[end] = 100001;
                    end++;
                }
            }
            if(end < nums.size() && nums[end] != nums[start]){
                count = 1;
                start = end;
                end = start+1;
            }
        }
        sort(nums.begin(), nums.end());
        int k = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 100001)
                k++;
        }
        return k;
    }
};