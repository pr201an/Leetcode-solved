class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> v;
        int maxL = height[0];
        for(int i=0; i<height.size(); i++){
            v.push_back(maxL);
            maxL = max(maxL, height[i]);
        }
        int maxR = height[height.size()-1];
        for(int i=height.size()-1; i>=0; i--){
            v[i] = min(maxR, v[i]);
            maxR = max(maxR, height[i]);
        }
        // for(int i=0; i<v.size(); i++){
        //     cout << v[i] << " ";
        // }
        int ans=0;
        for(int i=0; i<v.size(); i++){
            if(v[i] - height[i] > 0)
                ans += (v[i] - height[i]);
        }
        return ans;
    }
};