class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        const int N = 1e5+1;
       vector<int>divs(N,0);
       vector<long long>divs_sum(N,0);
       for(int i =1 ; i<N ;i++){
        for(int j = i ; j<N ;j+=i){
            divs[j]++;
            divs_sum[j]+=i;
        }
       }
       int ans = 0 ;
       for(auto it : nums){
        if(divs[it]==4){
            ans +=divs_sum[it];
        }
       }
       return ans ;
    }
};