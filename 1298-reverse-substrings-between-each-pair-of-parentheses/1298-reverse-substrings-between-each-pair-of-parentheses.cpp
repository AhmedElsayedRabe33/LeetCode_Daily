class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        int n = s.size();
        vector<int>vis(n+2);
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            }
            if (s[i] == ')') {
                int lst_idx = st.top();
                st.pop();
                vis[lst_idx] = i;
                vis[i] = lst_idx;
            }
        }
        int  idx = 0  , dir = 1;
        string ans;

        while(idx < n){
            if(s[idx]=='(' or s[idx]==')')
                idx= vis[idx],dir*=-1;
            else
                ans +=s[idx];
            idx+=dir;
        }
        return ans;
    }
};