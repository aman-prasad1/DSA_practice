class Solution {
public:
    int passThePillow(int n, int time) {
        // APPROACH 2
        // int i = 1;
        // while(time){
        //     while(i < n && time != 0){
        //         i++;
        //         time--;
        //     }
        //     while(i > 1 && time != 0){
        //         i--;
        //         time--;
        //     }
        // }
        // return i;


        // APPROACH 2
        int trips = time / (n-1);
        return (trips % 2 == 0)? (time % (n - 1) + 1) : (n - time % (n - 1));
    }

    
    
};
