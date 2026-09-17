class Solution {
public:
    auto mrg2(int a, int b) { return min(a, b); }
    vector<vector<int>> sparse_min;

    void build(vector<int> v) {
        int n = v.size();
        int levels = __lg(n) + 1;
        sparse_min.assign(levels, vector<int>(n));
        sparse_min[0] = v;
        for (int msk = 1; (1ll << msk) <= n; ++msk) {
            for (int i = 0; i + (1ll << msk) <= n; ++i) {
                sparse_min[msk][i] =
                    mrg2(sparse_min[msk - 1][i],
                         sparse_min[msk - 1][i + (1ll << (msk - 1))]);
            }
        }
    }
    int query2_MIN(int l, int r) {
        int msk = __lg(r - l + 1);
        return mrg2(sparse_min[msk][l], sparse_min[msk][r - (1ll << msk) + 1]);
    }

    int minSumOfLengths(vector<int> arr, int target) {
        int n = arr.size();
        vector<int> pre(n + 1, 1e9);
        pre[0] = arr[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + arr[i];
        }
        vector<array<int, 3>> have;
        for (int i = 0; i < n; i++) {
            int want = target + (i ? pre[i - 1] : 0);
            int it =
                lower_bound(pre.begin() + i, pre.end(), want) - pre.begin();
            int val = pre[it] - (i ? pre[i - 1] : 0);
            if (val == target)
                have.push_back(array<int, 3>{i, it, it - i + 1});
            // cout <<i <<" "<<it<<" "<<pre[it]-(i?pre[i-1] : 0)<<endl;
        }
        int ans = 2e9;
        vector<int> vals;
        for (auto& [a, b, c] : have) {
            vals.push_back(c);
        }
        if (vals.size())
            build(vals);
        for (int i = 0; i < have.size(); i++) {
            int a = lower_bound(have.begin() + i + 1, have.end(),
                                array<int, 3>{have[i][1] + 1, 0, 0}) -
                    have.begin();
            int b = have.size() - 1;
            if (a <= have.size() - 1 and a <= b) {
                int mn = query2_MIN(a, b);
                // cout<<i<<" " <<a <<" "<<b << " "<<mn<<endl;
                ans = min(ans, mn + have[i][2]);
            }
        }
        return (ans == 2e9 ? -1 : ans);
    }
};