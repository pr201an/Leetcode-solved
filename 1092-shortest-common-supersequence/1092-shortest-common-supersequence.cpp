class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<vector<int>> L(n+1, vector<int>(m+1));
        for(int i=0; i<n+1; i++){
            for(int j=0; j<m+1; j++){
                if(i==0 || j==0){
                    L[i][j] = 0;
                    continue;
                }
                if(str1[i-1] == str2[j-1]){
                    L[i][j] = 1+L[i-1][j-1];
                }
                else L[i][j] = max(L[i-1][j], L[i][j-1]);
            }
        }
        int i = n, j = m;
        string ans;
        while(i > 0 && j > 0){
            if(str1[i-1] == str2[j-1]){
                ans.push_back(str1[i-1]);
                --i;
                --j;
            }
            else if(L[i][j-1] > L[i-1][j]){
                ans.push_back(str2[j-1]);
                --j;
            }
            else{
                ans.push_back(str1[i-1]);
                --i;
            }
        }
        while(i>0){
            ans.push_back(str1[i-1]);
            --i;
        }
        while(j>0){
            ans.push_back(str2[j-1]);
            --j;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};