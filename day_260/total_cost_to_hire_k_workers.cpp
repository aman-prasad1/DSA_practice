class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        long long ans = 0;

        priority_queue<int, vector<int>, greater<int>> leftElements;
        priority_queue<int, vector<int>, greater<int>> rightElements;

        for(int i = 0; i < candidates && i < n; i++){
            leftElements.push(costs[i]);
        }
        
        for(int i = n - 1, j = 0; i >= candidates && j < candidates; j++, i--){
            rightElements.push(costs[i]);
        }

        int left = candidates;
        int right = n - candidates -1;
        while(k){
            int leftTop = INT_MAX, rightTop = INT_MAX;
            if(!leftElements.empty()) leftTop = leftElements.top();
            if(!rightElements.empty()) rightTop = rightElements.top();

            if(leftTop <= rightTop){
                ans += leftTop;
                leftElements.pop();
                if(left <= right) leftElements.push(costs[left++]);
            }
            else{
                ans += rightTop;
                rightElements.pop();
                if(left <= right){
                    rightElements.push(costs[right--]);
                }
            }
            k--;
        }
        return ans;
    }
};
