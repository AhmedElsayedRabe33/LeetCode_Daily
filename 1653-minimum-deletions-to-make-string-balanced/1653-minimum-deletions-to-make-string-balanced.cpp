class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size() , a= count(s.begin(),s.end(),'a');
        int b = n - a;
        int ans = min(a , b);
        int cnt = 0 ;
        vector<int>pre_a(n),pre_b(n);
        pre_a[0] = (s[0]=='a');
        pre_b[0] = (s[0]=='b');
        for(int i = 1 ; i < n ; i++ ){
            pre_a[i] = pre_a[i-1] +(s[i]=='a') ;
            pre_b[i] = pre_b[i-1] +(s[i]=='b') ;
        }
        for(int i = 0 ; i <n ; i++){
            int rem_a = pre_a[n-1] - pre_a[i];
            int rem_b = pre_b[i];
            ans = min(ans , rem_a + rem_b);
        }
        return ans ;
    }
};