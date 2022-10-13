class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](int x,int y){
            string a = to_string(x), b = to_string(y);
            return a+b>b+a;
        });
        string ans;
        for(int i=0; i<nums.size(); i++){
            ans += to_string(nums[i]);
        }
        if(ans[0] == '0')
            return "0";
        return ans;
        
    }
};