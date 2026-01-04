class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0 ;
        for(auto it : nums){
            vector<int>have ;
            int sum = 0;
            for(int i = 1 ; i*i <=it ;i++){
                if(it%i ==0){
                   have.push_back(i),sum+=i;
                    if(i!=(it/i))
                        have.push_back(it/i),sum+=it/i;
                }
                if(have.size()>4){
                    break;
                }
            }
                if(have.size()==4){
                    ans +=sum;
                }
        }
       return ans ;
    }
};