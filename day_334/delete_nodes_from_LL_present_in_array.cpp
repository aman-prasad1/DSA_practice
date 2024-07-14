class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, bool> mp;
        for(int i : nums){
            mp[i] = true;
        }

        ListNode* temp = new ListNode(-1);
        temp->next = head;

        ListNode* curr = temp;
        ListNode* next = head;

        while(next){
            if(!mp[next->val]){
                curr->next = next;
                curr = next;
            }
            next = next->next;
        }
        curr->next = next;
        return temp->next;
    }
};
