class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> cnt(32, 0);
        for (auto it : nums) {
            bitset<32> cur(it);
            for (int i = 0; i < 32; i++) {
                cnt[i] += (cur[i]);
            }
        }
        int ans = 0, MOD = 1e9 + 7;
        for (int j = 0; j < k; j++) {
            long long  cur = 0;
            for (int i = 0; i < 32; i++) {
                if (cnt[i]) {
                    cur |= (1LL << i);
                    cnt[i]--;
                }
            }
            int me = ((cur%MOD) * (cur%MOD) )%MOD;
            ans = (ans + me) % MOD;
        }
        return ans;
    }
};