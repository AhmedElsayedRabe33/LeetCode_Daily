class Solution {
public:
    int countCommas(int n) {
        int ans = 0 ;
        for(int i = 1; i <=n ;i++){
            string x = to_string(i);
            ans+=(x.size()/4);
        }
        return ans;
    }
};