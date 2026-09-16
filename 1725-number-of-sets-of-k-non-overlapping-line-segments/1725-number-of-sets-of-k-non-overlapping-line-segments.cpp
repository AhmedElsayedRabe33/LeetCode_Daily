class Solution {
public:
    int numberOfSets(int n, int k) {
        // i want to count how many ways to cover two or more points at plane 
        // n is 1000 !! 
        // n^2 ??!
        const int MOD = 1e9+7;
        vector dp(n+2,vector(k+2,vector<int>(2,-1)));
        function<int(int  ,int , bool)>calc=[&](int idx , int rem , bool ok)->int{
            if(rem==0)
            return 1;
            if(idx==n){
                return (rem==0? 1 : 0);
            }
            int &ret = dp[idx][rem][ok];
            if(~ret)
                return ret;
            ret = 0 ;
            if(ok==1){
                ret = (ret + calc(idx, rem-1 ,0))%MOD;
                ret = (ret + calc(idx+1, rem ,1))%MOD;
            }
            else{
                ret = (ret + calc(idx+1, rem ,0))%MOD;
                ret = (ret + calc(idx+1, rem ,1))%MOD;
            }
            return ret;
        };
        int ans = calc(0,k,0);
        return ans ;
    }
};