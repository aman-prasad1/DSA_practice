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
    ListNode* mergeNodes(ListNode* head) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        ListNode* root = new ListNode('0/');
        ListNode* rc = root;
        ListNode* curr = head->next;
        int sum = 0;
        while(curr){
            sum += curr->val;
            
            if(curr->val == 0){
                ListNode* temp = new ListNode(sum);
                rc->next = temp;
                rc = temp;
                sum = 0;
            }
            curr = curr->next;
        }
        
        return root->next;
    }
};
