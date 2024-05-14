class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();

        vector<string> ans;
        int i = 0;
        while(i < n){
            int num = nums[i];
            string temp = to_string(num);
            int range = nums[i++];
            while(i < n && nums[i] == range+1){
                range++;
                i++;
            }
            if(num != range) temp += "->" + to_string(range);
            ans.push_back(temp);
        }
        return ans;
    }
};
