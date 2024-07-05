class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        if(!head->next->next) return {-1, -1};

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = curr->next;

        int i = 2;
        vector<int> ind;
        while(next){
            if((curr->val < prev->val && curr->val < next->val) || curr->val > prev->val && curr->val > next->val){
                ind.push_back(i);
            }
            i++;
            prev = curr;
            curr = next;
            next = next->next;
        }
        
        int n = ind.size();
        if(n < 2) return {-1,-1};

        int maxDistance = ind[n-1]-ind[0];
        int minDistance = INT_MAX;

        for(i=0; i<n-1; i++){
            minDistance = min(minDistance, (ind[i+1]-ind[i]));
        }

        return {minDistance, maxDistance};

    }
};
