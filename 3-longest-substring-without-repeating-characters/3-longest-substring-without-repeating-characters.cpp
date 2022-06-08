class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int start = -1, ans = 0;
        for(int i=0;i<s.size();i++){
            m[s[i]] = -1;
        }
        for(int i=0;i<s.size();i++){
            if(m[s[i]] == -1){
                ans = max(ans, i-start);
            }
            else if(m[s[i]] != -1){
                start = max(start,m[s[i]]);
                ans = max(ans, i-start);
            }
            m[s[i]] = i;
        }
        return ans;
    }
};