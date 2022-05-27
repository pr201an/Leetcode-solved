class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        for(int i=0;i<nums2.size();i++){
            m[nums2[i]] = i;
        }
        stack<int> potans;
        for(int i=nums2.size()-1;i>=0;i--){
            int temp = nums2[i];
            while(!potans.empty() && nums2[i] >= potans.top()){
                potans.pop();
            }
            if(!potans.empty())
                nums2[i] = potans.top();
            else nums2[i] = -1;
            potans.push(temp);
        }
        for(auto i : m){
            cout << i.first << " " << i.second << endl;
        }
        for(int i=0; i<nums1.size(); i++){
            nums1[i] = nums2[m[nums1[i]]];
        }
        return nums1;
    }
};