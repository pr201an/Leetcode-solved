class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = s.size(), count = 0;
        for(int i=size-1; i>=0; i--){
            if(s[i] != 32)
                count++;
            if(s[i] == 32 && count != 0)
                break;
        }
        return count;
    }
};