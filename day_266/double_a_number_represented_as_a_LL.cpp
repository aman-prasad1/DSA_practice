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
    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = head->next;

        while(curr){
            curr->next = prev;
            prev = curr;
            curr = next;
            if(next) next = next->next;
        }
        return prev;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        head = reverseList(head);

        ListNode* curr = head;
        int carry = 0;

        while(curr){
            int dbl = (curr->val * 2) + carry;
            curr->val = dbl % 10;
            carry = dbl / 10;
            if(!curr->next) break;
            curr = curr->next;
        }

        if(carry){
            ListNode* temp = new ListNode(carry);
            curr->next = temp;
        }

        head = reverseList(head);
        return head;
    }
};
