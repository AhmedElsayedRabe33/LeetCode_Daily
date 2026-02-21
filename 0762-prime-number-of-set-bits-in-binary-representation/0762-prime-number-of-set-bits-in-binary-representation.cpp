class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; i++) {
            int cnt = 0;
            for (int j = 32; j >= 0; j--) {
                if (i & (1ll << j)) {
                    cnt++;
                }
            }

            bool ok = true;
            for (int j = 2; j * j <= cnt; j++) {
                if (cnt % j == 0) {
                    ok = false;
                    break;
                }
            }
            if (ok && cnt != 1) {
                ans++;
            }
        }
        return ans;
    }
};