class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int ans = 0, n = digits.size();
        set<vector<int>> st;
        for (int msk = 1; msk < (1 << n); msk++) {
            vector<int> cur;
            for (int i = 0; i < n; i++) {
                if (msk & (1 << i)) {
                    cur.push_back(digits[i]);
                }
            }
            if (cur.size() == 3) {
                sort(cur.begin(), cur.end());
                do {
                    st.insert(cur);
                } while (next_permutation(cur.begin(), cur.end()));
            }
        }
        for (auto it : st) {
            if (it.back() % 2 == 0 and it[0] != 0)
                ans++;
        }
        return ans;
    }
};