class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> v;
        int temp = 1;
        while(temp < arr[0]){
            v.push_back(temp);
            temp++;
        }
        for(int i=1; i<arr.size(); i++){
            int n = arr[i] - arr[i-1];
            int j = 1;
            while(n>1){
                v.push_back(arr[i-1]+j);
                j++;
                n--;
            }
        }
        for(int i=0; i<v.size(); i++){
            cout << v[i] << " ";
        }
        if(k > v.size() && v.size() != 0){
            return arr[arr.size()-1] + (k-v.size());
        }
        if(k > v.size() && v.size() == 0){
            return arr[arr.size()-1] + k;
        }
        return v[k-1];
    }
};