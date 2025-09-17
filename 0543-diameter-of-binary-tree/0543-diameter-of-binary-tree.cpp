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
    int maxheight = max(left,right);
    int height = maxheight+1;
    return height;
}
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        int option1 = diameterOfBinaryTree(root->left);
        int option2 = diameterOfBinaryTree(root->right);
        int option3 = getheight(root->left) + getheight(root->right);
        int maxi = max(option1 , max(option2 , option3));
        return maxi;
    }
};