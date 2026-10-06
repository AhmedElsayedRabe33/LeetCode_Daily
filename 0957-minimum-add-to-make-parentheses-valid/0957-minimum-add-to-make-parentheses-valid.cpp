class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for (auto it : s) {
            if (st.empty() or it == '(') {
                st.push(it);
            } else if (it == ')' and st.size() and st.top()=='(') {
                st.pop();
            } else {
                st.push(it);
            }
        }
        return st.size();
    }
};