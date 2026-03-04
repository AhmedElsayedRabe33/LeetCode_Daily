class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0 ;
        int n =mat.size() , m = mat[0].size();
        for(int i = 0 ; i <n ; i++){
            for(int j=0 ; j <m ; j++){
                bool ok = true;
                if(mat[i][j]==1){
                    for(int k = 0 ; k < n ; k++){
                        if(k==i)
                            continue;
                        if(mat[k][j]){
                            ok = false;
                            break;
                        }
                    }
                     for(int k = 0 ; k < m ; k++){
                        if(k==j)
                            continue;
                        if(mat[i][k]){
                            ok = false;
                            break;
                        }
                    }
                    ans+=ok;
                }
            }
        }
            return ans ;

    }
};