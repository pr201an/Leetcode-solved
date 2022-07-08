class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++) mp[arr[i]]++;
        for(int i=0;i<arr.size();i++){
            if(mp[arr[i]]==0);
            else{
                int x=2*arr[i];
                if(arr[i]<0 && abs(arr[i])%2==0) x=arr[i]/2;
                if(mp.find(x)!=mp.end())
                {
                    mp[x]--;
                    mp[arr[i]]--;
                }
            }
        }
        for(auto i:mp){
            if(i.second) return false;
        }
        return true;
    }
};