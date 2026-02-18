class Solution {
public:
    bool hasAlternatingBits(int n) {
        int msb_pos = 31 - __builtin_clz(n);
        for (long long  i = msb_pos; i > 0; i--) {
             bool a = n & (1 << i);
            bool b = n & (1 << (i - 1));
            if (a == b)
                return false;
        }
        return true;
    }
};