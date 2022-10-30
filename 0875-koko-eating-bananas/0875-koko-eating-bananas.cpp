class Solution {
public:
    bool fnc(vector<int> weights, int mid, int h){
        int reqhour = 0;
        for(int i=0; i<weights.size(); i++){
            if(weights[i] <= mid)
                reqhour++;
            else if(weights[i]%mid == 0)
                reqhour += weights[i]/mid;
            else reqhour += weights[i]/mid + 1;
        }
        if(reqhour <= h)
            return true;
        else return false;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = 0;
        for(int i=0; i<piles.size(); i++){
            hi = max(piles[i], hi);
        }
        while(lo < hi){
            int mid = (hi+lo)/2;
            if(fnc(piles, mid, h)){
                hi = mid;
            }
            else
                lo = mid+1;
        }
        return hi;
    }
};