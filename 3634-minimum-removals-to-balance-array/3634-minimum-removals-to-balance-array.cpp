class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = n-1 ;
        for(int i = 0 ; i < n ; i++){
            long long  me = (long long )nums[i] *(long long ) k ;
            int cur = i ;
            auto it = upper_bound(nums.begin(),nums.end(),me)-nums.begin();
            cur+=n-it;
            ans = min(ans , cur);
        }
        return ans ; 
    }
};