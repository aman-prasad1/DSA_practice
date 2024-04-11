class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());

        queue<int> q;
        for(int i=0; i<deck.size(); i++){
            q.push(i);
        }
        vector<int> ans(deck.size());
        for(int i : deck){
            int front = q.front();
            q.pop();
            ans[front] = i;
            if(!q.empty()){
                front = q.front();
                q.pop();
                q.push(front);
            }
        }
        return ans;
    }
};
