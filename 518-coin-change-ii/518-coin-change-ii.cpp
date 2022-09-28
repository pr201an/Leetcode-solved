class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector< vector<int>> K(coins.size()+1, vector<int>(amount+1));
        for(int i=0; i<coins.size()+1; i++){
            for(int j=0; j<amount+1; j++){
                if(j == 0){
                    K[i][j] = 1;
                    continue;
                }
                if(i == 0){
                    K[i][j] = 0;
                    continue;
                }
                if(coins[i-1] <= j){
                    K[i][j] = K[i-1][j] + K[i][j-coins[i-1]];
                }
                else K[i][j] = K[i-1][j];
            }
        }
        return K[coins.size()][amount];
    }
};