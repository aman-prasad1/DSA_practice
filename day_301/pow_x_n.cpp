class Solution {
public:
    double myPow(double x, int n) {
        double num = 1;
        long long temp = n;
        if(temp < 0) temp = -temp;
        while(temp>0){
            if(temp%2==1){
                num = num * x;
                temp--;
            }
            else{
                x = x*x;
                temp/=2;
            }
        }
        if(n < 0){
            num = 1.0/num;
        }
        return num;
    }
};
