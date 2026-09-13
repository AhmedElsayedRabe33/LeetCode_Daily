class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int ans =0 , n = img1.size();
        vector<pair<int,int>>a,b;
        for(int i =0 ;i <n ;i++){
            for(int j= 0 ; j <n ;j++){
                if(img1[i][j] == 1){
                    a.push_back({i,j});
                }
                if(img2[i][j] == 1){
                    b.push_back({i,j});
                }
            }
        }
        map<pair<int,int>,int>mp;
        for(auto [aa,bb] : a){
            for(auto [cc,dd] : b){
                int x = aa-cc , y = bb-dd;
                mp[{x,y}]++;
                ans = max(ans, mp[{x,y}]);
            }
        }
        return ans ;
    }
};