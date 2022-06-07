class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int smol = 0, big = 0;
        int sum = 0, ans = INT_MAX;
        while(big <= nums.size()){
            if(sum < target){
                cout << sum << " ";
                if(big != nums.size())
                    sum += nums[big];
                big++;
            }
            else if(sum > target){
                cout << sum << " ";
                ans = min(big-smol, ans);
                sum -= nums[smol];
                smol++;
            }
            else if(sum == target){
                cout << sum << " ";
                ans = min(big-smol, ans);
                sum -= nums[smol];
                smol++;
            }
        }
        if(ans == INT_MAX)
            return 0;
        else
            return ans;
    }
};