class Solution {
public:
    bool checkOnesSegment(string s) {
        s.erase(unique(s.begin(), s.end()), s.end());
        int cnt = 0;
        for (auto it : s) {
            cnt += (it == '1');
            if (cnt > 1)
                return false;
        }
        return true;
    }
};