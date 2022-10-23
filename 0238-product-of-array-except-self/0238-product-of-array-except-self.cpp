class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero = 0, mul = 1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0)
                zero++;
            else mul *= nums[i];
        }
        if(zero == 1){
            for(int i=0; i<nums.size(); i++){
                if(nums[i] == 0)
                    nums[i] = mul;
                else nums[i] = 0;
            }
        }
        else if(zero == 0){
            for(int i=0; i<nums.size(); i++){
                nums[i] = mul/nums[i];
            }
        }
        else{
            for(int i=0; i<nums.size(); i++){
                nums[i] = 0;
            }
        }
        return nums;
    }
};