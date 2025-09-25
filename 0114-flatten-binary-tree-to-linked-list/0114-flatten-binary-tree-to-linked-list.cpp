class Solution {
public:
    void solvetree(TreeNode* root, vector<TreeNode*>& nodes) {
        if(root==NULL){
            return;
        } 
        nodes.push_back(root);
        solvetree(root->left, nodes);
        solvetree(root->right, nodes);
    }

    void flatten(TreeNode* root) {
        if(root==NULL){
            return;
        }
        vector<TreeNode*> nodes;
        solvetree(root, nodes);

        for(int i=0; i < nodes.size() - 1; i++) {
            nodes[i]->left = NULL;
            nodes[i]->right = nodes[i+1];
        }
        // Handle last node
        // nodes.back()->left = NULL;
        // nodes.back()->right = NULL;
    }
};
