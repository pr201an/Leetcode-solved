class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0)
            return 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == val)
                nums[i] = 51;
        }
        sort(nums.begin(), nums.end());
        if(nums[nums.size()-1] != 51)
            return nums.size();
        else{
            int count = 0;
            while(nums[count] != 51){
                count++;
            }
            return count;
        }
    }
};