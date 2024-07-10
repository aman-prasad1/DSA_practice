class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;

        for(string operation : logs){
            if(operation == "../" && ans > 0){
                ans--;
            }
            else if(operation != "./" && operation != "../" ){ // This means operataion == "x/"
                ans++;
            }
        }

        return ans;
    }
};
