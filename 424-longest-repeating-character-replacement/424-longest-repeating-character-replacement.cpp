class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> map;
        int left = 0, right = 0;
        int ans = 0, maxlen = 0;
        while(right < s.size()){
            map[s[right]]++;
            for(auto x:map){
                maxlen = max(maxlen, x.second);
            }
            if((right - left - maxlen + 1) <= k){
                ans = max(ans,right-left+1);
            }
            else{
                map[s[left]]--;
                left++;
            }
            right++;
        }
        return ans;
    }
};