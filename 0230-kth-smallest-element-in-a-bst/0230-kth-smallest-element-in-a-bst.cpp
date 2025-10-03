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

void doinorder(TreeNode* root, vector<int>&arr){
    if(root==NULL){
        return;
    }
    doinorder(root->left,arr);
    arr.push_back(root->val);
    doinorder(root->right,arr);
}

    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;

        doinorder(root,arr);

        int ans = arr[k-1];
        return ans;
    }
};