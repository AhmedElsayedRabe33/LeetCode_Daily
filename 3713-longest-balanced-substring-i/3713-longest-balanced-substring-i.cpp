class Solution {
public:
    int longestBalanced(string s) {
        int ans = 0, n = s.size();
        vector pre(n + 2, vector<int>(26, 0));
        for (int i = 0; i < n; i++) {
            pre[i][s[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            for (int j = 1; j < n; j++) {
                pre[j][i] += pre[j - 1][i];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int cnt = 0;
                bool ok = true;
                for (int k = 0; k < 26; k++) {
                    int cur = pre[j][k] - (i - 1 >= 0 ? pre[i - 1][k] : 0);
                    if (cur > 0) {
                        if (cnt == 0 ) {
                            cnt = cur;
                        } else if (cnt !=cur) {
                            ok = false;
                            break;
                        }
                    }
                }
                if (ok) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};