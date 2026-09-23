class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int ans = 2e9, n = nums.size();
        vector<int> pre(n), suff(n);
        long long sum = 0;
        for (int i = 0, j = n - 1; i < n; i++, j--) {
            if (i) {
                pre[i] = pre[i - 1] + nums[i];
            } else {
                pre[i] = nums[i];
            }
            if (j == n - 1) {
                suff[j] = nums[j];
            } else {
                suff[j] = suff[j + 1] + nums[j];
            }
            sum += nums[i];
        }
        if (x > sum)
            return -1;
        reverse(suff.begin(), suff.end());
        int tst = x;
        auto it = lower_bound(suff.begin(), suff.end(), tst) - suff.begin();
        if (suff[it] == tst and (it + 1) <= n) {
            ans = min<int>(ans, (it + 1));
        }
        for (int i = 0; i < n; i++) {
            int want = x - pre[i];
            if (want > 0) {
                auto it =
                    lower_bound(suff.begin(), suff.end(), want) - suff.begin();
                // cout <<(i+1) << " "<<(it) <<" "<<suff[it]<<" "<<want<<endl;
                if (suff[it] == want and ((i + 1) + (it + 1)) <= n) {
                    ans = min<int>(ans, (i + 1) + (it + 1));
                }
            } else if (want == 0) {
                ans = min(ans, i + 1);
            } else {
                break;
            }
        }
        return (ans == 2e9 ? -1 : ans);
    }
};