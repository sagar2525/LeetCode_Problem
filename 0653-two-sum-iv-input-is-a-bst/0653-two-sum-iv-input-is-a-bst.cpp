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
void storeinorder(TreeNode* root,vector<int>& arr){
    if(root==NULL){
        return;
    }

    storeinorder(root->left,arr);
    arr.push_back(root->val);
    storeinorder(root->right,arr);
}
bool checktwosum(vector<int> arr,int k){
    int n = arr.size();
    int s =0;
    int e = n-1;
    while(s<e){
        int sum = arr[s] + arr[e];
        if(sum == k){
            return true;
        }
        if(sum>k){
            e--;
        }
        if(sum<k){
            s++;
        }
    }
    return false;
}

    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        storeinorder(root,arr);
        bool ans = checktwosum(arr,k);
        return ans;
    }
};