class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        // state of dp is i , j
        int n = s1.size(), m = s2.size();
        vector dp(n + 2, vector<int>(m + 2, -1));
        function<int(int, int)> calc = [&](int i, int j) -> int {
            if (i == n && j == m)
                return 0;
            if(i==n){
                int sum = 0 ;
                for(int k = j ; k < m ;k++){
                    sum+=int(s2[k]);
                }
                return sum;
            }
            if(j==m){
                int sum = 0 ;
                for(int k = i ; k < n ;k++){
                    sum+=int(s1[k]);
                }
                return sum;
            }
            int& ret = dp[i][j];
            if (~ret)
                return ret;
            ret = 1e9;
            if (s1[i] == s2[j])
                ret = min(ret, calc(i + 1, j + 1));
            ret = min(ret, int(s1[i]) + calc(i + 1, j));
            ret = min(ret, int(s2[j]) + calc(i, j + 1));
            return ret;
        };
        return calc(0, 0);
    }
};