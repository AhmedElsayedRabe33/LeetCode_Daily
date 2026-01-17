class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long ans = 0  , n = bottomLeft.size();
        for(int i  = 0 ; i < n ; i++){
            for(int j = i+1 ; j <n ;j++){
                long long  x1 = max(bottomLeft[i][0],bottomLeft[j][0]);
                long long  x2 = min(topRight[i][0],topRight[j][0]);
                long long  y1 = max(bottomLeft[i][1],bottomLeft[j][1]);
                long long  y2 = min(topRight[i][1],topRight[j][1]);
                if((x2-x1>0) &&( y2-y1>0)){
                    long long cur = min(x2-x1,y2-y1);
                    ans = max(ans , cur);
                }
            }
        }
        return ans * ans*1LL ;
    }
};