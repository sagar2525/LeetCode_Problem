/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

int getlength(ListNode*& head){
    ListNode* temp = head;
    int count = 0;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count;

}

TreeNode* createtree(ListNode* & head , int length){
    if(head==NULL  || length <=0){
        return NULL;
    }

    // LNR
    // L
    TreeNode* leftsubtree = createtree(head, length/2);
    //N
    TreeNode* root = new TreeNode(head->val);
    root->left = leftsubtree;

    // ab head mid per khdaa hai , usko aage bhejo 
    head = head->next;
    // ab head right part of LL k start node pr khdaa hoga
    TreeNode* rightsubtree = createtree(head , length-length/2-1);
    root->right = rightsubtree;
    return root; 

}

    TreeNode* sortedListToBST(ListNode* head) {
        int length = getlength(head);
        TreeNode* newtree = createtree(head,length);
        return newtree;
    }
};