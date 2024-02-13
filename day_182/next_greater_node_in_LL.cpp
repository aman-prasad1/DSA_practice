class Solution {
public:
    vector<int> solve(vector<int>& arr){
        int n = arr.size();
        vector<int> ans(n, 0);
        stack<int> st;
        st.push(0);
        for(int i=n-1; i>=0; i--){
            while(st.top() != 0 && st.top() <= arr[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(arr[i]);
        }

        return ans;
    }


    vector<int> nextLargerNodes(ListNode* head) {
        if(head == NULL){
            return {};
        }
        vector<int> arr;
        ListNode* temp = head;
        while(temp != NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }

        vector<int> ans = solve(arr);
        return ans;
    }
};