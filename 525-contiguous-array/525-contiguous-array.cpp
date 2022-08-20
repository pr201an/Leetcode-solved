class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> ump;
        ump[0] = -1;
        int maxlen = 0, count = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1)
                count = count + 1;
            else count = count - 1;
            if(ump.find(count) != ump.end())
                maxlen = max(maxlen, i-ump[count]);
            else
                ump[count]=i;
        }
        return maxlen;
    }
};