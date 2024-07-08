// APPROACH 1:- USING QUEUE

// class Solution {
// public:
//     int findTheWinner(int n, int k) {
        
//         queue<int> q;
//         for(int i=1; i<=n; i++){
//             q.push(i);
//         }

//         while(q.size() != 1){
//             for(int i=1; i<k; i++){
//                 int front = q.front();
//                 q.pop();
//                 q.push(front);
//             }

//             q.pop();
//         }

//         return q.front();
//     }
// };

// APPROACH 2:- USING RECURSION

class Solution {
    int solve(int n, int k, int s, vector<int>& arr){
        if(arr.size() == 1) return arr[0];

        s = (s + k - 1) % n;
        arr.erase(arr.begin()+s);

        return solve(n-1, k, s, arr);
    }
public:
    int findTheWinner(int n, int k) {
        
        vector<int> arr;

        for(int i=1; i<=n; i++){
            arr.push_back(i);
        }

        return solve(n, k, 0, arr);
    }
};
