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

    void solve(TreeNode* root,vector<TreeNode*>&newtree){
        if(root==NULL){
            return;
        }

        newtree.push_back(root);

        solve(root->left,newtree);
        solve(root->right,newtree);

    }
    
    void flatten(TreeNode* root) {
        if(root==NULL){
            return;
        }
        vector<TreeNode*> newtree;

        solve(root,newtree);

        for(int i=0;i<newtree.size()-1;i++){
            newtree[i]->left = NULL;
            newtree[i]->right = newtree[i+1];
        }
    }
};