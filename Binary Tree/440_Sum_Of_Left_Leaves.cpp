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
    
    /*
        O(n) - time since we have to visit each node
        O(h) - space since the recusive stack can be h long, h can be n in worst case
    */
    

    void sumOfLeftLeavesHelper(TreeNode * Node, bool is_left, int & sum){
        
        if(!Node){
            return;
        }
        
        if(!Node->left && !Node->right && is_left){
            sum += Node->val;
            return;
        }
        
        sumOfLeftLeavesHelper(Node->left, true, sum);
        sumOfLeftLeavesHelper(Node->right, false, sum);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        
        if(!root){
            return 0;
        }
        
        int sum = 0;
        sumOfLeftLeavesHelper(root->left, true, sum);
        sumOfLeftLeavesHelper(root->right, false, sum);
        return sum;
    }
};