class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int num = tickets[k];
        if (num <= 1)
            return k + 1;
        int ans = 0;
        for (int i = 0; i < tickets.size(); i++)
        {
            if (tickets[i] < num)
                ans += tickets[i];
            else
            {
                if (i > k)
                    ans += num - 1;
                else
                    ans += num;
            }
        }
        return ans;
    }
};