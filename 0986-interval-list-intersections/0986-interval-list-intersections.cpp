class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i=0, j=0;
        vector<vector<int>> ans;
        while(i<firstList.size() && j<secondList.size()){
            int lo = max(firstList[i][0], secondList[j][0]);
            int hi = min(firstList[i][1], secondList[j][1]);
            if(lo<=hi)
                ans.push_back({lo, hi});
            if(secondList[j][1] > firstList[i][1])
                i++;
            else j++;
        }
        return ans;
    }
};