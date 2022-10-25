class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int ans = 0, mod = 1e9+7;
        sort(arr.begin(), arr.end());
        for(int i=0; i<arr.size()-2; i++){
            int one = arr[i];
            int two = i+1, three = arr.size()-1;
            while(two < three){
                if(arr[two] + arr[three] == target-one){
                    int templ = 1, tempr = 1;
                    while(two < three && arr[two] == arr[two+1]){
                        templ++;
                        two++;
                    }
                    while(three > two && arr[three] == arr[three-1]){
                        tempr++;
                        three--;
                    }
                    if(two == three){
                        ans = (ans%mod + (templ%mod *(templ-1)%mod)/2)%mod;
                    }
                    if(two!=three)
                    {
                        ans = (ans%mod + (templ%mod* tempr%mod)%mod)%mod;	 
                    }
                    two++;
                    three--;
                }
                else if(arr[two] + arr[three] < target-one){
                    two++;
                }
                else three--;
            }
        }
        return ans;
    }
};