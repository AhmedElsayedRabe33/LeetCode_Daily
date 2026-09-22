class Solution {
public:
    struct Node {
        int total_product = 1;
        map<int, int> frq;
    };
    vector<int> resultArray(vector<int>& nums, int k,
                            vector<vector<int>>& queries) {
        const int sq = 320;
        int n = nums.size();
        int num_blocks = (n + sq - 1) / sq;
        vector<Node> blocks(num_blocks);
        auto build = [&](int idx) -> void {
            // at the beging and if u update block
            blocks[idx].total_product = 1;
            blocks[idx].frq.clear();
            int st = idx * sq, en = min(n , (idx + 1) * sq);
            // remember en is exclusive
            int cur_pro = 1;
            for (int i = st; i < en; i++) {
                cur_pro = (1LL*cur_pro * nums[i]) % k;
                blocks[idx].frq[cur_pro]++;
            }
            blocks[idx].total_product = cur_pro;
        };
        for (int b = 0; b < num_blocks; ++b) {
            build(b);
        }
        auto update = [&](int idx, int val) -> void {
            nums[idx] = val;
            int idx_block = idx / sq;
            build(idx_block);
        };
        vector<int> ans;
        auto calc = [&](int start, int x) -> int {
            int res = 0, cur = 1;
            int b_start = start / sq;
            int end_idx = min(n , (b_start + 1) * sq );
            // also exclusive
            for (int i = start; i <end_idx ; i++){
                cur= (1LL * cur * nums[i])%k;
                res+=(cur==x);
            }
            // from start to end 
            // we dont have to check on the end block 
           for(int j = b_start + 1; j < num_blocks; j++){
                for(auto &[val, count] : blocks[j].frq){
                    if((cur * val) % k == x){
                        res += count; 
                    }
                }
                cur = (1LL *cur * blocks[j].total_product) % k;
            }
            return res;
        };
        for(auto& q : queries) {
            update(q[0], q[1]);
            ans.push_back(calc(q[2], q[3]));
        }
        return ans;
    }
};