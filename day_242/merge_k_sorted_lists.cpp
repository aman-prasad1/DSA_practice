class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> minheap;

        for(auto head : lists){
            while(head){
                minheap.push(head->val);
                head = head->next;
            }
        }

        ListNode* head = new ListNode('0');
        ListNode* curr = head;
        while(!minheap.empty()){
            int val = minheap.top();
            minheap.pop();

            ListNode* temp = new ListNode(val);
            curr->next = temp;
            curr = temp;
        }
        return head->next;
    }
};