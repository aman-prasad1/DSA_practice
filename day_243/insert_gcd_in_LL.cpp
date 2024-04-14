class Solution{
public:
    ListNode *insertGreatestCommonDivisors(ListNode *head){
        ListNode *temp = head;
        while (temp->next){
            int val2 = temp->next->val;
            int val1 = temp->val;
            int val3 = __gcd(val1, val2);
            
            ListNode *middle = new ListNode(val3);
            middle->next = temp->next;
            temp->next = middle;
            temp = temp->next->next;
        }
        return head;
    }
};
