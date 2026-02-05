class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
       int n = nums.size();
        vector<int>ans(n);
        for(int i = 0 ; i < n ; i++){
            if(nums[i]>=0){
                int cur = (i+nums[i])%n;
                ans[i] = nums[cur];
            }
            else{
                int cur = (i - (-1*nums[i])%n + n)%n;
                ans[i] = nums[cur];
            }
        }
            return ans ; 
    }
};