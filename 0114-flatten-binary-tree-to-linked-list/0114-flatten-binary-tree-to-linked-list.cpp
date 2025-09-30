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

 vector<TreeNode*> arr;


 void callfunction(vector<TreeNode*>arr){
    if(arr.empty()){
        return;
    }
    for(int i=1;i<arr.size();i++){
        arr[i-1]->left = NULL;
        arr[i-1]->right = arr[i];
    }
    arr.back()->left = NULL;     
    arr.back()->right = NULL;
 }

 void solvearr(TreeNode* root){
    if(root==NULL){
        return;
    }
    arr.push_back(root);
    solvearr(root->left);
    solvearr(root->right);
 }

    void flatten(TreeNode* root) {

        solvearr(root);
        callfunction(arr);
    }
};