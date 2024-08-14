// use binaray serch operation from from 0 to max element in the array. Use two pointer approach to calculate total number of pairs less than or equal to to the mid.

class Solution {
    int countPairs(vector<int>& nums, int mid){
        int n = nums.size();

        int left = 0, cnt = 0;
        for(int right = 0; right < n; right++){
            while(nums[right] - nums[left] > mid){
                left++;
            }
            cnt += right - left;
        }
        return cnt;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int s = 0, e = nums[n-1];
        while(s <= e){
            int mid = s + (e-s)/2;
            int pairs = countPairs(nums, mid);

            if(pairs >= k) e = mid-1;
            else s = mid + 1;
        }
        return s;
    }
};
