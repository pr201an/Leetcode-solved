class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> v;
        stack<int> st;
        for(int i=0; i<heights.size(); i++){
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if(st.empty())
                v.push_back(-1);
            else v.push_back(st.top());
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        vector<int> v2;
        for(int i=heights.size()-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if(st.empty())
                v2.push_back(heights.size());
            else
                v2.push_back(st.top());
            st.push(i);
        }
        reverse(v2.begin(), v2.end());
        int ans = INT_MIN;
        for(int i=0; i<v.size(); i++)
            ans = max(ans, (v2[i]-v[i]-1)*heights[i]);
        return ans;
    }
};