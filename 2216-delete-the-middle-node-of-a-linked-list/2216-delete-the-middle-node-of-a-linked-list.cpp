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
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next==NULL){
            return NULL;
        }
        ListNode* temp = head;
        int i=0;
        while(temp!=NULL){
            temp = temp->next;
            i++;
        }
        int mid = i/2;
        ListNode* curr = head;
        int k = 0;
        while (k < mid - 1) {      
            curr = curr->next;
            k++;
        }
        ListNode* todelete = curr->next;
        curr->next = curr->next->next;
        return head;
    }
};