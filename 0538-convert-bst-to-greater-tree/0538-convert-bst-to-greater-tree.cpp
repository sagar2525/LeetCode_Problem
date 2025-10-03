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

void storein(TreeNode* root,vector<int>& inorder){
    if(root==NULL){
        return;
    }
    storein(root->left,inorder);
    inorder.push_back(root->val);
    storein(root->right,inorder);
}

int i=0;
void restoreinorder(TreeNode* root,vector<int>& inorder){
    if(root==NULL){
        return;
    }
    restoreinorder(root->left,inorder);
    root->val = inorder[i];
    i++;
    restoreinorder(root->right,inorder);

}
    TreeNode* convertBST(TreeNode* root) {
        vector<int> inorder;

        storein(root,inorder);

        for(int i=inorder.size()-2;i>=0;i--){
            inorder[i] += inorder[i+1];
        }

        restoreinorder(root,inorder);
        return root;
    }
};