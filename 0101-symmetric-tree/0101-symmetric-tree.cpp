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


int value =0;

void solveleft(TreeNode* rootL,TreeNode* rootR){
    if(rootL==NULL && rootR==NULL){
        return;
    }
    if((rootL == NULL && rootR !=NULL) || (rootL != NULL && rootR ==NULL)){
        value++;
        return;
    }
    else if(rootL->val!=rootR->val){
        value++;
        return;
    }
    else{
        solveleft(rootL->left,rootR->right);
        solveleft(rootL->right,rootR->left);
    }
    // else if(rootL == NULL && rootR!=NULL){
    //     value++;
    //     return;
    // }
    // else if(rootL != NULL && rootR==NULL){
    //     value++;
    //     return;
    // }
    // else if(rootL == NULL || rootR==NULL){
    //     return;
    // }
    
}


    bool isSymmetric(TreeNode* root) {

        solveleft(root->left,root->right);
        if(value>0){
            return false;
        }
        else{
            return true;
        }

    }
};