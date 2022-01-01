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
    
    /**
    
    Complexity Analysis:

    Let N be the number of nodes in the binary tree.

    Time complexity: O(N) since we visit all nodes once.

    Space complexity: O(N) since we need stacks to do recursion, and the maximum depth of the recursion is the height of the tree, which is O(N) in the worst case and O(log(N)) in the best case.
    
    
    **/
    
    void maxAncestorDiffHelper(TreeNode* root, int & max_diff, int max_val, int min_val){
        if(!root){
            return;
        }
        
        max_val = max(max_val, root->val);
        min_val = min(min_val, root->val);
        max_diff = max(max_diff, abs(min_val-max_val));
        
        maxAncestorDiffHelper(root->left, max_diff, max_val, min_val);
        maxAncestorDiffHelper(root->right, max_diff, max_val, min_val);

        
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int max_diff = 0;
        maxAncestorDiffHelper(root, max_diff, INT_MIN, INT_MAX);
        return max_diff;
    }
};