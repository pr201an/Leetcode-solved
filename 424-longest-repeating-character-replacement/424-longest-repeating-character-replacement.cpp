class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLength = 0;
        int i = 0, j = 0, n = s.length();
        int maxCharCountInCurrentWindow = 0;
        int count[26] = {0};
        
        while(j < n) {
            count[s[j] - 'A']++;
            maxCharCountInCurrentWindow = max(maxCharCountInCurrentWindow, count[s[j]-'A']);
            
            if(j - i + 1 - maxCharCountInCurrentWindow > k) {
                count[s[i] - 'A']--;
                i++;
            }
            
            maxLength = max(maxLength, j - i + 1);
            j++;
        }
        
        return maxLength;
    }
};