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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int> st;
        // st.push(0);

        vector<int> vcc;
        ListNode* temp = head;
        while(temp!=NULL){
            vcc.push_back(temp->val);
            temp = temp->next;
        }

        vector<int> ans(vcc.size(),0);
        for(int i=0;i<vcc.size();i++){
            int curr = vcc[i];
            while(!st.empty() && vcc[i] > vcc[st.top()]){
                ans[st.top()] = vcc[i]; 
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};