class Solution {
public:
    int minOperations(string s, int k) {
        long long z = 0, n = s.size();
        for (auto it : s)
            z += (it == '0');
        if (!z)
            return 0;

        // min opearation can we take !!
        for (long long  i = 1; i <= n; i++) {
            long long flips = i * k; // total
            if ((flips - z) & 1) // if reminder is odd that's mean you convert
                                 // some one to zero this isn't allowed
                continue;
            if (i & 1) {
                // if now i have odd operation
                // we must try (op-1) on 1 to make them 1
                // and make op on 0 to flips them to one !
                if (z <= flips && flips <= (z * (i) + ((n - z) * (i - 1))))
                    return i;
            } else {
                if (z <= flips && flips <= (z * (i-1) + ((n - z) * (i))))
                    return i;
            }
        }
        return -1;
    }
};