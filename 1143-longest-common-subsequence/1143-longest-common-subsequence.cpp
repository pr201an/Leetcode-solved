class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector< vector<int>> K(text1.size()+1, vector<int>(text2.size()+1));
        for(int i=0; i<text1.size()+1; i++){
            for(int j=0; j<text2.size()+1; j++){
                if(i==0 || j==0){
                    K[i][j] = 0;
                    continue;
                }
                if(text1[i-1] == text2[j-1]){
                    K[i][j] = 1+K[i-1][j-1];
                }
                else{
                    K[i][j] = max(K[i-1][j], K[i][j-1]);;
                }
            }
        }
        return K[text1.size()][text2.size()];
    }
};