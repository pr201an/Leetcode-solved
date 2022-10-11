class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        string r = s;
        reverse(r.begin(), r.end());
        vector<vector<int>> L(n+1, vector<int>(n+1));
        for(int i=0; i<n+1; i++){
            for(int j=0; j<n+1; j++){
                if(i == 0 || j == 0){
                    L[i][j] = 0;
                    continue;
                }
                if(s[i-1] == r[j-1]){
                    L[i][j] = L[i-1][j-1] + 1;
                }
                else L[i][j] = max(L[i-1][j], L[i][j-1]);
            }
        }
        return n - L[n][n];
    }
};