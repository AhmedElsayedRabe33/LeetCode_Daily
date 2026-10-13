class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans = 0;
        auto cmp = [&](int a, int b) -> bool { return abs(a) < abs(b); };
        sort(nums.begin(), nums.end(), cmp);
        int l = 0, r = nums.size() - 1;
        bool turn = true;
        while (l <= r) {
            if (turn) {
                ans += nums[r] * nums[r];
                r--;
            } else {
                ans -= nums[l] * nums[l];
                l++;
            }
            turn ^= 1;
        }
        return ans;
    }
};