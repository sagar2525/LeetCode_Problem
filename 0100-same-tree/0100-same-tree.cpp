class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL){
            return true;
        }
        else if(p == NULL && q != NULL){
            return false;
        }
        else if(p != NULL && q == NULL){
            return false;
        }
        else if(p->val != q->val){
            return false;
        }
        else {
            // check left and right recursively
            bool leftSame = isSameTree(p->left , q->left);
            bool rightSame = isSameTree(p->right , q->right);
            return leftSame && rightSame;
        }
    }
};
