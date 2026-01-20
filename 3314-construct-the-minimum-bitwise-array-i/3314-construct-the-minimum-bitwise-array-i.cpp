class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,-1);
        for(int i = 0 ; i <n ; i++){
            for(int j = 1 ; j <=100000 ; j++){
                int cur = j | (j+1);
                if(cur==nums[i]){
                    ans[i] = j;
                    break;
                }
            }
        }
        return ans ;
    }
};