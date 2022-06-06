class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() == 0 || nums.size() == 1)
            return ans;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-2;i++){
            int one = nums[i];
            int two = i + 1, three = nums.size()-1;
            while(two < three){
                vector<int> temp;
                if(nums[two] + nums[three] > (0-one))
                    three--;
                else if(nums[two] + nums[three] < (0-one))
                    two++;
                else if(nums[two] + nums[three] == (0-one)){
                    temp.push_back(one);
                    temp.push_back(nums[two]);
                    temp.push_back(nums[three]);
                    ans.push_back(temp);
                    while(two < three && nums[two] == nums[two+1])
                        two++;
                    while(three > two && nums[three] == nums[three-1])
                        three--;               
                    two++;
                    three--;
                }
            }
            while(i+1 < nums.size() && nums[i+1] == nums[i]) i++;
        }
        return ans;
    }
};