class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize) return false;

        sort(hand.begin(), hand.end());
        vector<bool> visited(n, false);

        int i = 0;
        int next = -1;

        while(i <= n-groupSize){
            if(next != -1){
                i = next;
                next = -1;
            }

            int prev = hand[i], cnt = 1;
            visited[i++] = true;

            while(cnt < groupSize && i < n){
                if(!visited[i]){
                    if(hand[i] == prev+1){
                        cnt++;
                        prev = hand[i];
                        visited[i] = true;
                    }
                    else if(next == -1){
                        next = i;
                    }
                }
                i++;
            }
            cout << endl;
            if(cnt != groupSize) return false;

            if(next != -1) i = next;
        }
        return true;
    }
};