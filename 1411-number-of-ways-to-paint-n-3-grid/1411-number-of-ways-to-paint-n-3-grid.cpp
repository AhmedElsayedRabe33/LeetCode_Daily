class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;
        vector dp(n+2,vector(4,vector(4,vector<int>(4,-1))));
        function<int(int , int , int , int)>calc=[&](int idx , int c1 , int c2 , int c3)->int{
            if(idx>=n)
                return 1;
            int &ret = dp[idx][c1][c2][c3];
            if(~ret)
                return ret;
            ret = 0 ;
            for(int i = 0 ; i < 3 ; i++){
                if(i!=c1){
                    for(int j = 0 ; j <3 ; j++){
                        if(i!=j && j!=c2){
                            for(int k = 0 ; k <3 ; k++){
                                if(j!= k && k!=c3){
                                    ret = (ret +calc(idx+1,i,j,k))%MOD;
                                }
                            }
                        }
                    }
                }
            }
            return ret;
        };
        return calc(0,3,3,3);
    }
};