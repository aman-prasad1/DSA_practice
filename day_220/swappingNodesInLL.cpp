class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head->next) return head;
        ListNode* first = head;

        for(int i=1; i<k; i++){
            first = first->next;
        }

        ListNode* slow = head;
        ListNode* fast = first;

        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        swap(slow->val, first->val);
        return head;
    }
};