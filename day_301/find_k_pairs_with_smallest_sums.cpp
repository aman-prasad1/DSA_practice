class Solution {
public:
    // APPROACH 1
    // vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // priority_queue<pair<int,pair<int,int>>> maxHeap;
        // vector<vector<int>> ans;

        // for(int i=0; i<nums1.size(); i++){
        //     for(int j=0; j<nums2.size(); j++){
        //         maxHeap.push({(nums1[i] + nums2[j]), {nums1[i], nums2[j]}});
        //         if(maxHeap.size() > k){
        //             maxHeap.pop();
        //         }
        //         if(maxHeap.size() == k && (nums1[i] + nums2[j]) >= maxHeap.top().first) break;
        //     }
        // }

        // while(!maxHeap.empty()){
        //     auto top = maxHeap.top();
        //     maxHeap.pop();
        //     ans.push_back({top.second.first, top.second.second});
        // }
        // return ans;
    // }

    // APPROACH 2
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;

        auto cmp = [&](const pair<int,int>& a,const pair<int,int>& b){
             return (nums1[a.first]+nums2[a.second]) > nums1[b.first]+nums2[b.second];
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
        for(int i=0;i<min(k,(int)nums1.size());i++){
             pq.push({i,0});
        }

        while(k-- && !pq.empty()){
            pair<int,int> idx = pq.top();
            pq.pop();
            res.push_back({nums1[idx.first],nums2[idx.second]});
            if(idx.second+1<nums2.size()){
                pq.push({idx.first,idx.second+1});
            }
        }
        return res;
    }
};
