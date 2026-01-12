class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        vector<int>prv = points[0];
        int ans = 0 ;
        for(int i =1 ; i < points.size();i++){
            auto it = points[i];
             ans +=max(abs(it[0]-prv[0]),abs(it[1]-prv[1]));
             prv = it;
        }
        return ans ;
    }
};