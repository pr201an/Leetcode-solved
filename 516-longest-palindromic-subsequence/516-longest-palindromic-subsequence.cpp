class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        int n = s.size(), m = r.size();
        vector<vector<int>> L(s.size()+1, vector<int>(r.size()+1));
        for(int i=0; i<n+1; i++){
            for(int j=0; j<m+1; j++){
                if(i==0 || j==0){
                    L[i][j] = 0;
                    continue;
                }
                if(s[n-i] == r[m-j]){
                    L[i][j] = 1+L[i-1][j-1];
                }
                else L[i][j] = max(L[i][j-1], L[i-1][j]);
            }
        }
        return L[n][m];
    }
};