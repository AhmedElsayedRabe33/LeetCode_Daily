#define ll int
class Solution {
public:
    int longestBalanced(string s) {
        ll n = s.size();
    // first i want to hande if we have some aaaa , bbbb , cccc
    ll a = 0, b = 0, c = 0;
    for (int i = 0; i < n; i++) {
        int j = i, len = 1;
        while (j + 1 < n && s[j] == s[j + 1]) {
            j++;
            len++;
        }
        if (s[i] == 'a') {
            a = max(a, len);
        }
        if (s[i] == 'b') {
            b = max(b, len);
        }
        if (s[i] == 'c') {
            c = max(c, len);
        }
        i = j;
        // cout <<i<<nl;
    }
    // now we can try a , b || a,c || b,c
    // pre[r]  = pre[l-1]
    function<int(string)> calc = [&](string me)-> int {
        int n = me.size();
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; i++) {
            if (me[i] == me[0])
                pre[i + 1] = 1;
            else
                pre[i + 1] = -1;
            pre[i + 1] += pre[i];
        }
        map<int, int> frq;
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            if (frq.count(pre[i])) {
                ans = max(ans, i - frq[pre[i]]);
            } else {
                frq[pre[i]] = i;
            }
        }
        return ans;
    };
    int ret = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') {
            continue;
        }
        string tmp;
        int j = i;
        while (j < n && s[j] != 'a') {
            tmp.push_back(s[j]);
            j++;
        }
        i = j - 1;
        ret = max(ret, calc(tmp));
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == 'b') {
            continue;
        }
        string tmp;
        int j = i;
        while (j < n && s[j] != 'b') {
            tmp.push_back(s[j]);
            j++;
        }
        i = j - 1;
        ret = max(ret, calc(tmp));
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == 'c') {
            continue;
        }
        string tmp;
        int j = i;
        while (j < n && s[j] != 'c') {
            tmp.push_back(s[j]);
            j++;
        }
        i = j - 1;
        ret = max(ret, calc(tmp));
    }
    // what if a ,b , c
    vector<int> prea(n + 1, 0),preb(n+1,0);
    for (int i =1 ;i<=n ;i++) {
        prea[i] = prea[i-1];
        prea[i]+=(s[i-1]=='a');
        prea[i]-=(s[i-1]=='b');

        preb[i] = preb[i-1];
        preb[i]+=(s[i-1]=='b');
        preb[i]-=(s[i-1]=='c');
    }
    map<pair<int,int >,int>frqall;
    for (int i =0 ; i <=n ;i++) {
        pair<int ,int > me = {prea[i],preb[i]};
        if (frqall.count(me)) {
            ret = max(ret , i - frqall[me]);
        }
        else {
            frqall[me] = i;
        }
    }
    ret = max({ret ,a , b, c});
    return ret;
    }
};