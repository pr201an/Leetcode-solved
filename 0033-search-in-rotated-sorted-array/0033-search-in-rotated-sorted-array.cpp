class Solution {
public:
    int search(vector<int>& nums, int target) {
        int hi = nums.size()-1, lo=0;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] >= nums[lo]){
                if(target >= nums[lo] && target <= nums[mid])
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }
            else{
                if(target <= nums[hi] && target >= nums[mid])
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
        }
        return -1;
    }
};