class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        vector<int>frq(1e5,0);
        for(auto it : nums)
            frq[it]++;
        int ans = 0 ;
        for(int i = 0 ; i < 1e5 ; i++){
            if(frq[i]>1){
                ans = i;
                break;
            }
        }
        return ans;
    }
};