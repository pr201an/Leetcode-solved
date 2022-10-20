//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // bool isPalindrome(string str, int i, int j){
    //     string temp = str.substr(i, j-i+1);
    //     string temp2 = temp;
    //     reverse(temp2.begin(), temp.end());
    //     return (temp == temp2);
    // }
    int dp[1001][1001];
    bool isPalindrome(string X, int i, int j) {
        if(i == j)
            return true;
        if(i>j)
            return true;
    	while (i <= j) {
    		if (X[i] != X[j])
    			return false;
    		i++, j--;
    	}
    	return true;
    }

    int solve(string str, int i, int j){
        if(i>=j || isPalindrome(str, i, j)){
            dp[i][j] = 0;
            return 0;
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = INT_MAX;
        for(int k=i; k<=j-1; k++){
            int a,b;
            if(dp[i][k] != -1)
                a = dp[i][k];
            else{
                a = solve(str,i,k);
                dp[i][k] = a;
            }
            if(dp[k+1][j] != -1)
                b = dp[k+1][j];
            else{
                b = solve(str,k+1,j);
                dp[i][k] = b;
            }
            int temp_ans = a + b + 1;
            ans = min(ans, temp_ans);
        }
        return dp[i][j] = ans;
    }
    int palindromicPartition(string str)
    {
        // code here
        int N = str.size();
        memset(dp, -1, sizeof dp);
        return solve(str, 0, N-1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends