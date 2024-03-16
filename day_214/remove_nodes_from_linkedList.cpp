class Solution {
    ListNode* reverse(ListNode* head){
        if(!head->next) return head;

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = head->next;

        while(curr){
            curr->next = prev;
            prev = curr;
            curr = next;
            if(next)
                next = next->next;
        }
        return prev;
    }
public:
    ListNode* removeNodes(ListNode* head) {
        if(!head->next) return head;
        ListNode* ptr = new ListNode(INT_MAX);
        ptr->next = head;
        head = reverse(ptr);

        ListNode* maxNode = head;
        ListNode* curr = head;

        while(curr->next){
            if(curr->next->val < maxNode->val){
                curr->next = curr->next->next;
            }
            else{
                maxNode = curr->next;
                curr = curr->next;
            }
        }

        head = reverse(head);
        return ptr->next;
    }
};