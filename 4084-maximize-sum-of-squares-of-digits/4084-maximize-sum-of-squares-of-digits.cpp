class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans;
        while (sum > 0) {
            int val = min(sum, 9);
            ans += char(val + '0');
            sum -= val;
        }
        if (ans.size() > num)
            return "";
        while (ans.size() < num) {
            ans += '0';
        }
        return ans;
    }
};