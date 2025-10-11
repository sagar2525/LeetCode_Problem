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
class info{
    public:
    int minval;
    int maxval;
    int sum;
    bool isBST;
};

class Solution {
public:
    int mincal(int a,int b, int c){
        int minans = min(a,min(b,c));
        return minans;
    }
    int maxcal(int a,int b, int c){
        int maxans = max(a,max(b,c));
        return maxans;
    }
    

    info solve(TreeNode* root,int & sum){
        if(root == NULL){
            info temp;
            temp.minval = INT_MAX;
            temp.maxval = INT_MIN;
            temp.sum = 0;
            temp.isBST = true;
            sum = max(sum,temp.sum);
            return temp;
        }
        if(root->left ==NULL && root->right == NULL){
            info temp;
            temp.minval = root->val;
            temp.maxval = root->val;
            temp.sum = root->val;
            temp.isBST = true;
            sum = max(sum,temp.sum);
            return temp;
        }

        // LNR
        info leftans = solve(root->left,sum);
        info rightans = solve(root->right,sum);

        // N
        info currentans;
        currentans.minval = mincal(leftans.minval, rightans.minval, root->val);
        currentans.maxval = maxcal(leftans.maxval, rightans.maxval , root->val);
        currentans.sum = leftans.sum + rightans.sum + root->val;
        currentans.isBST = (root->val > leftans.maxval && root->val < rightans.minval && leftans.isBST && rightans.isBST);

        if(currentans.isBST){
            sum = max(sum,currentans.sum);
        }
        return currentans;
    
    }
    int maxSumBST(TreeNode* root) {
        // check for it is BST 
        // Maxsum
        int sum =0;
        solve(root,sum);
        return sum;
    }
};