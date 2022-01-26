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
    
    void DFS(TreeNode* root, queue<int> & q){
        
        if(!root){
            return;
        }
        
        DFS(root->left, q);
        q.push(root->val);
        DFS(root->right, q);
        
    }

    /*
    
    Runtime: O(m+n)
    Space: O(m+n)
    
    
    */
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        queue<int> q1;
        queue<int> q2;
        DFS(root1, q1);
        DFS(root2, q2);
        while(!q1.empty() && !q2.empty()){
            
            if(q1.front() < q2.front()){
                ans.push_back(q1.front());
                q1.pop();
            } else{
                ans.push_back(q2.front());
                q2.pop();
            }
        }
        
        while(!q1.empty()){
            ans.push_back(q1.front());
            q1.pop();
        }

        while(!q2.empty()){
            ans.push_back(q2.front());
            q2.pop();
        }
        
        return ans;
    }
};