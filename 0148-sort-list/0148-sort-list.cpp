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
    ListNode* sortList(ListNode* head) {
        ListNode* temp =head;
        vector<int> arr;
        int i =0;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        ListNode* sorted = head;
        sort(arr.begin(),arr.end());
        for(int i =0;i<arr.size();i++){
            sorted->val = arr[i];
            sorted = sorted->next;
        }
        return head;
    }
};