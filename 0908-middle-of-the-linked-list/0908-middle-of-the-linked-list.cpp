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
    ListNode* middleNode(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* curr = head;
        int i=1;
        int element=0;
        while(curr->next!=NULL){
            curr = curr->next;
            i++;
        }
        if(i%2==0){
            element = (i/2)+1;
        }
        else{
            element = i/2;
            element+=1;
        }
        int j=1;
        ListNode* temp = head;
        while(j!=element){
            temp = temp->next;
            j++;
        }
        head = temp;
        // int k=1;
        // while(temp->next!=NULL){
        //     temp = temp->next;
        //     k++;
        // }
        return head;

    }
};