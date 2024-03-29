//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> v(n+1, vector<int>(n+1));
        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                if(i == 0 || j == 0){
                    v[i][j] = 0;
                    continue;
                }
                if(i <= j)
                    v[i][j] = max(price[i-1]+v[i][j-i], v[i-1][j]);
                else v[i][j] = v[i-1][j];
            }
        }
        return v[n][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends