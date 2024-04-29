class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<pair<int,int>> sortedNum;

        for(int i=0; i<nums1.size(); i++){
            sortedNum.push_back(make_pair(nums2[i], nums1[i]));
        }

        sort(sortedNum.begin(), sortedNum.end(), greater<>());

        long long ans = 0, sum = 0;
        for(int i=0; i<nums1.size(); i++){
            sum += sortedNum[i].second;
            pq.push(sortedNum[i].second);

            if(pq.size() == k){
                ans = max(ans, sum * sortedNum[i].first);
                sum -= pq.top();
                pq.pop();
            }
        }
        return ans;
    }
};
