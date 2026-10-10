class Solution {
public:
    int minInsertions(string s) {
        // ))) ((
        int n = s.size();
        int cnt = 0, o = 0;
        for (int i = 0; i < n;) {
            if (s[i] == '(') {
                o++;
                i++;
            } else {
                if (i + 1 < n and s[i + 1] == ')') {
                    o--;
                    i += 2;
                } else {
                    cnt++;
                    o--;
                    i++;
                }
            }
            if (o < 0)
                cnt++, o = 0;
        }
        return cnt + o * 2;
    }
};