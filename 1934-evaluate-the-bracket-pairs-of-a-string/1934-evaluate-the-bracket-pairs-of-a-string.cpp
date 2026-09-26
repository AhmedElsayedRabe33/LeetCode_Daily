class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string, string> mp;
        for (auto it : knowledge) {
            mp[it[0]] = it[1];
        }
        string ans, cur;
        bool ok = false;
        for (auto it : s) {
            if (it == '(') {
                ok = true;
                continue;
            }
            if (ok) {
                cur += it;
            }
            if (it == ')') {
                cur.pop_back();
                if (mp.find(cur) != mp.end()) {
                    ans += mp[cur];
                } else {
                    ans += '?';
                }
                cur.clear();
                ok = false;
            }
            if (ok == false and (it >= 'a' and it <= 'z')) {
                ans += it;
            }
        }
        return ans;
    }
};