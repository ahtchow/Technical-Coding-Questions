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
    void maxDepthHelper(TreeNode* node, int &abs_depth, int cur_depth){
        if(!node) {
            return;
        }
        
        cur_depth++;
        abs_depth = max(abs_depth, cur_depth);
        maxDepthHelper(node->left, abs_depth, cur_depth);
        maxDepthHelper(node->right, abs_depth, cur_depth);
        
        
    }
    
    
    int maxDepth(TreeNode* root) {
        int max_depth = 0;
        maxDepthHelper(root, max_depth, 0);
        return max_depth;
    }
};