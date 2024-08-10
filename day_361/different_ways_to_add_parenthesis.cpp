class Solution {
    int cal(int a, int b, char op){
        if(op == '+') return a + b;
        if(op == '-') return a - b;
        if(op == '*') return a * b;
        return 0;
    }

    vector<int> solve(string equation){
        vector<int> res;
        if(equation.length() <= 2){
            res.push_back(stoi(equation));
            return res;
        }
        
        for(int i=0; i<equation.size(); i++){
            if(!isdigit(equation[i])){
                
                vector<int> left = solve(equation.substr(0, i));
                vector<int> right = solve(equation.substr(i+1));

                for(int a: left){
                    for(int b : right){
                        int val = cal(a, b, equation[i]);
                        res.push_back(val);
                    }
                }
            }
        }

        return res;
    }
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans = solve(expression);
        return ans;
    }
};
