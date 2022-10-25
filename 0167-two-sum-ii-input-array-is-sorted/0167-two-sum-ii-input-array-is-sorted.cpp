class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0,j=numbers.size()-1;
        vector<int> ans;
        sort(numbers.begin(), numbers.end());
        while(i<j){
            if(numbers[i] + numbers[j] == target){
                //cout << numbers[i] + numbers[j] << endl;
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;
            }
            else if(numbers[i] + numbers[j] > target){
                //cout << numbers[i] + numbers[j] << endl;
                j -= 1;
            }
            else if(numbers[i] + numbers[j] < target){
                //cout << numbers[i] + numbers[j] << endl;
                i += 1;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};