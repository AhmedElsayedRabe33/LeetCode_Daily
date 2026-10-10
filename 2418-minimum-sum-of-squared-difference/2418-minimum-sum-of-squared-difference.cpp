class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                               int k2) {
#define int long long

        vector<int> have;
        int n = nums1.size();
        for (int i = 0; i < n; i++) {
            have.push_back(abs(nums1[i] - nums2[i]));
        }
        int l = 0, r = 1e6, lim = 1e6;
        auto can = [&](int mid) -> bool {
            long long sum = 0;
            for (int i = 0; i < n; i++) {
                if (have[i] > mid)
                    sum += (have[i] - mid);
            }
            return (sum <= (k1 + k2));
        };
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (can(mid)) {
                lim = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        long long used = 0;
        for (auto& it : have) {
            if (it > lim) {
                used += (it - lim);
                it = lim;
            }
        }
        long long rem = (k1 + k2) - used;
        for (int i = 0; i < have.size() && rem > 0; i++) {
           if (have[i] == lim && have[i] > 0) {
                have[i]--;
                rem--;
            }
        }
        long long ans = 0;
        for (auto it : have) {
            ans += (it * it);
        }
        return ans;
#undef int
    }
};