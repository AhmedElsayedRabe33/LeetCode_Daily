class Solution {
public:
    bool hasAllCodes(string s, int k) {
       int n = s.size();
       long long need = (1ll<<k);
       set<long long > st;
       const long long mod = 1e9+9 , base = 53;
       vector<long long >powers(30);
       powers[0]=1;
       for(int i = 1 ; i < 25 ; i++){
        powers[i] = (powers[i-1] * base)%mod;
       }
       long long pat = 0;
       for(int i = 0 ; i < min<int>(k,n);i++){
            pat = ((pat * base)%mod + s[i])%mod;
       }
       st.insert(pat);
       for(int i = k ; i < n ; i++){
            pat = (pat - (s[i-k]*powers[k-1])%mod + mod )%mod;
            pat = (pat * base)%mod;
            pat = (pat + s[i])%mod;
            st.insert(pat);
       }
       return (st.size() == need);
    }
};
// 1 2 3 4 5 6