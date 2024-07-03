class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        int i = 0;
        long ans = 0;
        int neg = 0;
   
        while (s[i] == ' ' && i < n) i++;

        while ((s[i] <= '0'-1 || s[i] > '9' )&&i<n) {
            if (s[i] == '-') {
                neg = 1;
                i++;
                break;
            } else if (s[i] == '+') {
                i++;
                break;
            } 
            else if ((s[i] >= 'a' && s[i] <= 'z') || s[i] == '.')
                return 0;
        }

        while (s[i] == '0' && i < n) i++;
        
        while (i < n) {
            if (s[i] >= '0' && s[i] <= '9') {
                ans *= 10;
                ans += int(s[i] - '0');
                if (ans >2147483647) {
                    if(neg==1 && ans>=2147483648) return (-2147483648);
                    return 2147483647;
                }
            } 
            else break;
            i++;
        }

        if (neg) return (-ans);
        else return ans;
    }
};
