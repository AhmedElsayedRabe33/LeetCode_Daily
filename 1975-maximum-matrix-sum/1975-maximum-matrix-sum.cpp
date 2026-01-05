class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long  ans =  0, n = matrix.size(),m = matrix[0].size(),mn = 1e9 ,cnt = 0 ;
        for(int i = 0 ; i < n ;i++){
            for(int j = 0 ; j < m ; j++){
                ans+=abs(matrix[i][j]);
                cnt +=(matrix[i][j] < 0);
                mn = min<long long >(mn , abs(matrix[i][j]));
            }
        }
        if(cnt &1)
            ans -=2LL * mn;
        return ans ;
    }
};