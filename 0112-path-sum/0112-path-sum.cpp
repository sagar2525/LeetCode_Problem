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

bool sumof(TreeNode* root, int targetSum,int maxi){
    if(root == NULL){
        return false;
    }
    maxi += root->val;
    if(root->left==NULL && root->right == NULL){
        if(maxi == targetSum){
            return true;
        }
        else{
            return false;
        }
    }
    

    bool leftsum = sumof(root->left,targetSum,maxi);
    bool rightsum = sumof(root->right,targetSum,maxi);

    if(leftsum == false && rightsum == false){
        return false;
    }
    else if(leftsum == true && rightsum == false){
        return true;
    }
    else if(leftsum == false && rightsum == true){
        return true;
    }
    else{
        return true;
    }
}

    bool hasPathSum(TreeNode* root, int targetSum) {
        int maxi = 0;
        
        bool ans = sumof(root,targetSum,maxi);
        return ans;

    }
};