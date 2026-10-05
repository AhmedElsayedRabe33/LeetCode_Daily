class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0;
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            char it = s[i];
            if (it == '(') {
                st.push(i);
            } else {
                int diff = i - st.top();
                if (diff == 1) {
                    ans += (1 << (st.size() - 1));
                }
                st.pop();
            }
        }
        return ans;
    }
};