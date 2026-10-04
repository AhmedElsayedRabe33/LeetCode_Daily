class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size(), cnt = 0;
        vector dp(n + 1, vector<int> (n + 1, -1));
        function<int(int, int)> calc = [&](int idx, int open) -> int {
            if (idx == n) {
                return (open == 0);
            }
            int& ret = dp[idx][open];
            if (~ret)
                return ret;
            ret = 0;
            if (s[idx] == '(') {
                ret = max(ret, calc(idx + 1, open + 1));
            } else if (s[idx] == '*') {
                ret = max(ret, calc(idx + 1, open + 1));
                if (open - 1 >= 0) {
                    ret = max(ret, calc(idx + 1, open - 1));
                }
                ret = max(ret, calc(idx + 1, open));
            } else {
                if (open - 1 >= 0) {
                    ret = max(ret, calc(idx + 1, open - 1));
                }
                else{
                    ret = 0 ;
                    return ret;
                }
            }
            return ret;
        };
        return (calc(0,0));
    }
};