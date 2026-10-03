class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector dp(n + 1, vector(m + 1, vector<int>(101, -1)));
        auto ok = [&](int i, int j) -> bool {
            if (i < 0 or i >= n or j < 0 or j >= m)
                return false;
            return true;
        };
        int me = n + m - 1;
        bool ans = false;
        function<int(int, int, int)> calc = [&](int i, int j, int have) -> int {
            int nw = have + (grid[i][j] == '(' ? 1 : -1);
            if (nw < 0 or nw > 100) {
                return 0;
            }
            if (i == n - 1 and j == m - 1) {
                return (nw==0 ? 1 : 0);
            }
            int& ret = dp[i][j][have];
            if (~ret)
                return ret;
            ret = false;
            if (ok(i + 1, j)) {
                ret = max(ret, calc(i + 1, j, nw));
            }
            if (ok(i, j + 1)) {
                ret = max(ret, calc(i, j + 1, nw));
            }
            return ret;
        };
        ;
        return (calc(0, 0, 0) == 1);
    }
};