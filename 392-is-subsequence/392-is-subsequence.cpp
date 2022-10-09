class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> L(s.size()+1, vector<int>(t.size()+1));
        for(int i=0; i<s.size()+1; i++){
            for(int j=0; j<t.size()+1; j++){
                if(i==0 || j==0){
                    L[i][j] = 0;
                    continue;
                }
                if(s[i-1] == t[j-1]){
                    L[i][j] = 1+L[i-1][j-1];
                }
                else L[i][j] = max(L[i-1][j], L[i][j-1]);
            }
        }
        int i=s.size(), j=t.size();
        string ans;
        while(i>0 && j>0){
            if(s[i-1] == t[j-1]){
                ans.push_back(s[i-1]);
                i--; j--;
            }
            else if(L[i-1][j] > L[i][j-1])
                i--;
            else j--;
        }
        reverse(ans.begin(), ans.end());
        if(ans == s)
            return true;
        else return false;
    }
};