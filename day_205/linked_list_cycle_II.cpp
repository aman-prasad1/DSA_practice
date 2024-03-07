class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) break;
        }

        if(fast == slow){
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return fast;
        }
        return NULL;
    }
};