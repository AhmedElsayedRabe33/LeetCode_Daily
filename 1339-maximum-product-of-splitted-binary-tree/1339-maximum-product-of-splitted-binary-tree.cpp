/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int maxProduct(TreeNode* root) {
        // make sum prefix at sub_trees
        long long MOD = 1e9 + 7;
        long long ans = 0;
        function<int(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node)
                return 0;
            node->val += dfs(node->left) + dfs(node->right);
            return node->val;
        };
        long long total = dfs(root);
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if (!cur)
                continue;
            long long me = (total - cur->val) * cur->val;
            ans = max(ans, me);
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
        return ans % MOD;
    }
};