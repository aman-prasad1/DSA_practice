class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<double> avg;
        
        int i=0, j=n-1;
        while(i<j){
            double small = nums[i++];
            double large = nums[j--];
            
            avg.push_back((small+large)/2.0);
        }
        return *min_element(avg.begin(), avg.end());
    }
};
