class Solution {
public:
    long long countCommas(long long n) {
        if (n < 1000)
            return 0;
        long long  ans = 0;
        long long cur = 999;
        for (int i = 1; i; i++) {
            long long val = n - cur;
            cout <<val <<endl;
            if (cur <= n)
                ans += val;
            else
                break;
            string ok = to_string(cur);
            ok+="999";
            if(ok.size()>18)
                break;
            cur = stoll(ok);
        }
        return ans;
    }
};