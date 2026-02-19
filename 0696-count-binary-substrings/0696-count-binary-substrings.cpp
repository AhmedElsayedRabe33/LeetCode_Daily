class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        vector<int> me;
        int i = 0, a = 0, b = 0, ans = 0;
        while (i < n) {
            if (s[i] == '0') {
                if(b)
                me.push_back(b);
                while (i < n && s[i] == '0') {
                    a++;
                    i++;
                }
                b=0;
            } else {
                if(a)
                me.push_back(a);
                 while (i < n && s[i] == '1') {
                    b++;
                    i++;
                }
                a = 0;
            }
        }
        if (a) {
            me.push_back(a);
        }
        if (b) {
            me.push_back(b);
        }
        for (int i = 1 ;i < me.size() ; i++) {
                ans+=min(me[i],me[i-1]);
        }
        return ans;
    }
};