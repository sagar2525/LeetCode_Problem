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
ListNode* reverse(ListNode* prev,ListNode* curr){
    // base case
    if(curr==NULL){
        return prev;
    }
    // 1 case solve kerna hai 
    ListNode* forward = curr -> next;
    curr -> next = prev;

    return reverse(curr,forward);
}

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        return reverse(prev,curr);
    }
};