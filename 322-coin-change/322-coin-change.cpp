class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector< vector<int>> K(coins.size()+1, vector<int>(amount+1));
        for(int i=0; i<coins.size()+1; i++){
            for(int j=0; j<amount+1; j++){
                if(i == 0){
                    K[i][j] = INT_MAX-1;
                    continue;
                }
                if(j == 0){
                    K[i][j] = 0;
                    continue;
                }
                if(i == 1){
                    if(j % coins[0] == 0){
                        K[i][j] = j/coins[0];
                    }
                    else K[i][j] = INT_MAX-1;
                    continue;
                }
                if(coins[i-1] <= j){
                    K[i][j] = min(K[i-1][j], 1 + K[i][j-coins[i-1]]);
                }
                else K[i][j] = K[i-1][j];
            }
        }
        if(K[coins.size()][amount] == INT_MAX-1)
            return -1;
        else return K[coins.size()][amount];
    }
};