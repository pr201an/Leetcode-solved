class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n==0) return s;
        vector<vector<int>> L(n+1, vector<int>(n+1));
        string r = s;
        reverse(r.begin(), r.end());
        string ans;
        int max = 0;
        for(int i=0; i<n+1; i++){
            for(int j=0; j<n+1; j++){
                if(i==0 || j==0){
                    L[i][j] = 0;
                    continue;
                }
                if(s[n-i] == r[n-j]){
                    L[i][j] = 1+L[i-1][j-1];
                    if(L[i][j] > max){
                        string temp = s.substr(j-L[i][j],L[i][j]);
                        string revtemp = temp;
                        reverse(revtemp.begin(), revtemp.end());
                        if(temp == revtemp){
                            max = L[i][j];
                            ans = temp;
                        }
                    }
                }
                else L[i][j] = 0;
            }
        }
        return ans;
    }
};