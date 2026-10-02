class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<char> have;
        for (int i = 0; i < n; i++) {
            have.push_back('(');
        }
        for (int i = 0; i < n; i++) {
            have.push_back(')');
        }
        vector<string> ans;
        do {
            string cur;
            for (auto it : have) {
                if (cur.empty())
                    cur += it;
                else if (it == ')' and cur[cur.size() - 1] == '(')
                    cur.pop_back();
                else
                    cur += it;
            }
            string me;
            if (cur.empty()) {
                for (auto it : have)
                    me += it;
                ans.push_back(me);
            }
        } while (next_permutation(have.begin(), have.end()));
        return ans;
    }
};