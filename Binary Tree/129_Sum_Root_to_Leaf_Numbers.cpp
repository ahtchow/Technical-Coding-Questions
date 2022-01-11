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

    int sumRootToLeafStack(TreeNode* root) {
        stack<pair<TreeNode*,int>> stk;
        int ans = 0;
        stk.emplace(root, root->val);
        while(!stk.empty()){
            pair<TreeNode*,int> tmp = stk.top();
            stk.pop();
            if(tmp.first->left){
                stk.emplace(tmp.first->left,tmp.second * 2+ tmp.first->left->val);
            }
            if(tmp.first->right){
                stk.emplace(tmp.first->right,tmp.second * 2+ tmp.first->right->val);
            }
            if(!tmp.first->left && ! tmp.first->right){
                ans += tmp.second;
            }
            
        }
        return ans;
    }
    
    int sumNumbers(TreeNode* root) {
        int total_sum = 0;
        sumNumbersHelpers(root, 0, total_sum);
        return total_sum;
    }
};