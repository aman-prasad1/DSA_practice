class Solution {
public:
    bool judgeSquareSum(int c) {
        int a = 0;
        int b = sqrt(c);
        if(b*b == c) return true;
        
        while(a <= b){
            int equal = c - (b*b);
            if(equal == (a*a)){
                return true;
            }
            else if(equal < a*a){
                b--;
            }
            else{
                a++;
            }
        }
        return false;
    }
};
