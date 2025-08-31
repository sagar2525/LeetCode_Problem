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
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return true;
        }
        vector<int> arr;
        ListNode* temp = head;
        arr.push_back(temp->val);
        while(temp->next!=NULL){
            temp = temp ->next; 
            arr.push_back(temp->val);
               
        }
        vector<int> rev(arr.size());
        for(int i=0;i<arr.size();i++){
            rev[i] = arr[i];
        }
        reverse(rev.begin(),rev.end());
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=rev[i]){
                return false;
            }
            else{
                continue;
            }
        }
        return true;

    }
};