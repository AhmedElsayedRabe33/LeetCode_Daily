class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto it : s) {
            if (st.empty()) {
                st.push(it);
            } else if ((it == '}' or it == ']' or it == ')')) {
                if (it == '}') {
                    if (st.top() != '{')
                        return false;
                }
                if (it == ']') {
                    if (st.top() != '[')
                        return false;
                }
                if (it == ')') {
                    if (st.top() != '(')
                        return false;
                }
                st.pop();
            } else {
                st.push(it);
            }
        }
        return (st.empty());
    }
};