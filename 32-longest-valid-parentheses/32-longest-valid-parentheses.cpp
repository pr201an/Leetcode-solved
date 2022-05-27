class Solution {
public:
    int longestValidParentheses(string s) {
	int max_possible = 0;
        stack<int> st;
        st.push(-1);
        for(int i = 0 ; i < s.size(); i++)
        {
            if(s[i] == '(' )
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if(st.empty())
                    st.push(i);
                else
                {
                    int len = i - st.top();
                    max_possible = max(max_possible, len);
                }
            }
        }
        return max_possible;
	}
};