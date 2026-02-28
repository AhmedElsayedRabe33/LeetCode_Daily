class Solution {
public:
    int msb_pos(int x) { return 31 - __builtin_clz(x); }
    int add(int a , int b , int mod){
        return (a%mod  * b%mod )%mod;
    }
    int concatenatedBinary(int n) {
        int ans = 0;
        const int MOD = 1e9 + 7 ;
        long long mx =0 ;
        for (int i = 1, me = 0; i <= n; i++) {
            for (int j = msb_pos(i); j >= 0; j--) {
                  ans =ans * 2;
                  if(ans>=MOD)
                    ans-=MOD;
                if(i&(1<<j)){
                    ans =ans + 1;
                  if(ans>=MOD)
                    ans-=MOD;
                }
                me++;
            }
        }
        // cout <<mx;
        return ans ;
    }
};