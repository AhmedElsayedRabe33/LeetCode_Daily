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
    TreeNode* balanceBST(TreeNode* root) {
        dfs(root);
        return build(0,v.size()-1);
    }

private:
        vector<int> v;
    void dfs(TreeNode* me) {
        if (me == NULL)
            return;
        dfs(me->left);
        v.push_back(me->val);
        dfs(me->right);
    }

    TreeNode* build(int l, int r) {
        if (l > r) return NULL;

        int mid = (l + r) / 2;
        TreeNode* node = new TreeNode(v[mid]);
        node->left = build(l, mid - 1);
        node->right = build(mid + 1, r);
        return node;
    }
};