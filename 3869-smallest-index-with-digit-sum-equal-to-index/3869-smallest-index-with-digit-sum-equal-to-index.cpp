class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            string s = to_string(nums[i]);
            int sum = 0;
            for (auto it : s) {
                sum += (it - '0');
            }
            if (i == sum)
                return i;
        }
        return -1;
    }
};