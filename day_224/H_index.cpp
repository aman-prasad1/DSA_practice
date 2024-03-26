class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int ans=0;
        int cnt = 0;
        for(int i=citations.size()-1; i>=0; i--, cnt++)
        {
            if(citations[i]>=cnt+1)
            {
                ans = cnt+1;
            }
            else{
                break;
            }
        }
        return ans;
    }
};