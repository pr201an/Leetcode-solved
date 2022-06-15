class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int end = 0;
        deque<int> d;
        if(k == 0){
            int ans = INT_MIN, count = 0;
            for(int i=0; i<nums.size(); i++){
                if(nums[i] == 1){
                    count++;
                    ans = max(ans, count);
                }
                else{
                    ans = max(ans, count);
                    count = 0;
                }
            }
            return ans;
        }
        while(1){
            if(nums[end] == 1){
                d.push_back(1);
            }
            else if(nums[end] == 0){
                d.push_back(0);
                k--;
            }
            end++;
            if(k == 0 || end == nums.size()) break;
            
        }
        int ans = d.size();
        while(end < nums.size()){
            if(nums[end] == 1){
                d.push_back(1);
                int temp = d.size();
                ans = max(ans, temp);
            }
            else if(nums[end] == 0){
                if(d.front() == 1){
                    while(d.front() == 1)
                        d.pop_front();
                }
                d.pop_front();
                d.push_back(nums[end]);
                int temp = d.size();
                ans = max(ans, temp);
            }
            end++;
        }
        return ans;
    }
};