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
        O(h) - space since the recusive stack can be h long
    */
    
    void sumNumbersHelpers(TreeNode* node, int curr_sum, int & total_sum){
        
        if(!node){
            return;
        }
        
        curr_sum = (curr_sum * 10) + node->val;
        if(!node->left && !node->right){
            total_sum += curr_sum;
            return;
        }
        
        sumNumbersHelpers(node->left, curr_sum, total_sum);
        sumNumbersHelpers(node->right, curr_sum, total_sum);
        return;
        
    }
    
    int sumNumbers(TreeNode* root) {
        int total_sum = 0;
        sumNumbersHelpers(root, 0, total_sum);
        return total_sum;
    }
};