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
int getheight(TreeNode* root){
    if(root==NULL){
        return 0;
    }

    int left = getheight(root->left);
    int right = getheight(root->right);
    int maxi = max(left,right)+1;
    return maxi;
}
    int diam =INT_MIN;
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int lemax = getheight(root->left);
        int rhmax = getheight(root->right);
        int ans = lemax+rhmax;
        diam = max(ans,diam);

        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return diam;
    }
};