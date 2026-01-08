class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        // state of dp idx1,idx2, is_empty?
        int n = nums1.size(),m =nums2.size();
        vector dp(n+2,vector(m+2,vector<int>(3,-1)));
        function<int(int , int,bool )>calc=[&](int idx1 , int idx2 , bool is_empty)->int{
            if(idx1==n || idx2==m){
                return (is_empty == 0?-1e9:0);
            }
            int &ret = dp[idx1][idx2][is_empty];
            if(~ret)
                return ret;
            ret = -1e9;
            ret = max(ret , calc(idx1+1,idx2,is_empty));
            ret = max(ret , calc(idx1+1,idx2+1,is_empty));
            ret = max(ret ,(nums1[idx1]*nums2[idx2]) + calc(idx1+1,idx2+1,1));
            ret = max(ret , calc(idx1,idx2+1,is_empty));
            return ret;
        };
        return calc(0,0,0);
    }
};