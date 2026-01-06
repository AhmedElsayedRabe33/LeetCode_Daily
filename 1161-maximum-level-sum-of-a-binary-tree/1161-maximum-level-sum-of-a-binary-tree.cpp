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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int lvl = 1,bst =1 , sum = -1e9;
        while(!q.empty()){
            long long cur_sum = 0 ;
            int sz = q.size();
            for(int i = 0 ; i < sz ;i++){
                TreeNode* node = q.front();
                q.pop();
                cur_sum+=node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            if(cur_sum > sum){
                bst = lvl;
                sum = cur_sum;
            }
            lvl++;
        }
        return bst ;
    }
};