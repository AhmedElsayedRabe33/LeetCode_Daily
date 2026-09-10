/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        int ans = 0 ;
        function<pair<int,int>(TreeNode*)>dfs=[&](TreeNode* rt)->pair<int,int>{
            if(!rt)
                return {0,0};
            pair<int,int> l = dfs(rt->left);
            pair<int,int> r = dfs(rt->right);
            int val = rt->val;
            int sum = l.first + r.first + val;
            int cnt = l.second + r.second + 1;
            ans += ((sum/cnt) == rt->val);
            return {sum , cnt}; 
        };
        dfs(root);
        return ans ;
    }
};