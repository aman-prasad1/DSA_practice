class Solution {
public:
    int numSteps(string s) {
        int n = s.length();
        int steps = 0;

        for(int i = n-1; i>=1; ){
            if(s[i] == '0'){
                s.pop_back();
                i--;
            }
            else{
                int ind = i;
                string temp = "";
                while(ind >= 0 && s[ind] == '1'){
                    s.pop_back();
                    temp += "0";
                    ind--;
                }
                if(ind < 0){
                    s = "1" + temp;
                    i++;
                }
                else {
                    s[ind] = '1';
                    s += temp;
                }
            }
            steps++;
        }
        if(s[0] == '0') return steps + 1;
        return steps;
    }
};
