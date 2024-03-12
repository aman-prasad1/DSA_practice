class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int prefix_sum = 0;
        unordered_map<int, ListNode*> mp;
        mp[0] = dummy;
        ListNode* current = head;

        while (current) {
            prefix_sum += current->val;
            if (mp.find(prefix_sum) != mp.end()) {
                ListNode* to_delete = mp[prefix_sum]->next;
                int temp_sum = prefix_sum + to_delete->val;
                while (to_delete != current) {
                    mp.erase(temp_sum);
                    to_delete = to_delete->next;
                    temp_sum += to_delete->val;
                }
                mp[prefix_sum]->next = current->next;
            }
            else {
                mp[prefix_sum] = current;
            }
            current = current->next;
        }

        return dummy->next;
    }
};