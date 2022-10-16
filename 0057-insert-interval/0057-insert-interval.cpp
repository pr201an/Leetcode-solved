class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        if(intervals.size() == 0){
            ans.push_back(newInterval);
            return ans;
        }
        for(int i=0; i<intervals.size(); i++){
            if(intervals[i][1] >= newInterval[0] && intervals[i][1] <= newInterval[1]
              && intervals[i][0] <= newInterval[0])
                intervals[i][1] = newInterval[1];
            else if(intervals[i][0] >= newInterval[0] && intervals[i][1] >= newInterval[1]
                   && intervals[i][0] <= newInterval[1])
                intervals[i][0] = newInterval[0];
        }
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        // for(int i=0; i<intervals.size(); i++){
        //     cout << intervals[i][0] << " " << intervals[i][1] << endl;
        // }
        ans.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] <= ans[ans.size()-1][1] && 
               ans[ans.size()-1][1] <= intervals[i][1])
                ans[ans.size()-1] = {ans[ans.size()-1][0], intervals[i][1]};
            else if(intervals[i][0] >= ans[ans.size()-1][1])
                ans.push_back(intervals[i]);
        }
        return ans;
    }
};