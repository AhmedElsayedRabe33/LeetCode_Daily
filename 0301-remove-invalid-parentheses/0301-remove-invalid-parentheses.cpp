
int n, mn;
unordered_set<string> frq;
vector<string> ans;
void calc(const string& s, int idx, int cur_del, string& noww, int balance) {
    if (cur_del > mn || balance < 0)
        return;

    if (idx == n) {
        if (cur_del == mn && balance == 0) {
            if (frq.find(noww) == frq.end()) {
                ans.push_back(noww);
                frq.insert(noww);
            }
        }
        return;
    }

    noww.push_back(s[idx]);
    int new_balance = balance;
    if (s[idx] == '(')
        new_balance++;
    else if (s[idx] == ')')
        new_balance--;

    calc(s, idx + 1, cur_del, noww, new_balance);
    noww.pop_back();

    if (s[idx] == '(' || s[idx] == ')') {
        calc(s, idx + 1, cur_del + 1, noww, balance);
    }
}
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {

        frq.clear();
        ans.clear();
        mn = 0, n = s.size();
        stack<char> st;
        for (auto it : s) {
            if (it >= 'a' and it <= 'z')
                continue;
            if (st.empty() or it == '(')
                st.push(it);
            else if (st.top() == '(' and st.size())
                st.pop();
            else
                st.push(it);
        }
        mn = st.size();
        string cur = "";
        calc(s, 0, 0, cur,0);
        return ans;
    }
};