class Solution {
    void merge(vector<int>& nums, int left, int mid, int right){
        vector<int> temp;
        int l = left;
        int r = mid + 1;
        while (l <= mid && r <= right){
            if(nums[l] <= nums[r]){
                temp.push_back(nums[l++]);
            }
            else{
                temp.push_back(nums[r++]);
            }
        }
        while(l <= mid){
            temp.push_back(nums[l++]);
        }
        while(r <= right){
            temp.push_back(nums[r++]);
        }
        for(int i=left; i<=right; i++){
            nums[i]=temp[i-left];
        }

    }
    void merge_sort(vector<int>& nums, int start, int end){
        if(start >= end) return;

        int mid = start + (end-start)/2;
        merge_sort(nums, start, mid);
        merge_sort(nums, mid+1, end);
        merge(nums, start, mid, end);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums, 0, nums.size()-1);
        return nums;
    }
};
