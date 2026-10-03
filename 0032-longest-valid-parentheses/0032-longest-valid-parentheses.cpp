class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0, n = s.size();
        vector<int> dp(n + 1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (st.size()) {
                    int cur = st.top();
                    st.pop();
                    int len = i - cur + 1;
                    dp[i] = (cur ? dp[cur - 1] + len : len);
                    ans = max(ans , dp[i]);
                }
            }
        }
        return ans;
    }
};