class Solution {
    bool fnc(int mid, vector<int> arr, int d){
        int sum = 0;
        int dayj = 1;
        for(int i=0; i<arr.size(); i++){
            if(sum + arr[i] <= mid)
                sum += arr[i];
            else{
                sum = arr[i];
                dayj++;
            }
        }
        if(dayj <= d)
            return true;
        else return false;
    }
    
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxm = INT_MIN, sum = 0;
        for(int i=0; i<weights.size(); i++){
            maxm = max(maxm, weights[i]);
            sum += weights[i];
        }
        int lo = maxm, hi = sum, ans;
        while(lo <= hi){
            int mid = (lo+hi)/2;
            if(fnc(mid, weights, days)){
                ans = mid;
                hi = mid -1;
            }
            else lo = mid+1;
        }
        return ans;
    }
};