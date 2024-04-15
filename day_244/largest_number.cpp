bool cmp(int a, int b){
    return to_string(a)+to_string(b) > to_string(b)+to_string(a);
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);

        string ans = "";
        for(int num : nums){
            ans += to_string(num);
        }
        return (ans[0] == '0')? "0" : ans;
    }
};