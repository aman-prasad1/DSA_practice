class Solution {
    vector<int> nextSmaller(vector<int> arr){
        stack<int> s;
        s.push(-1);

        int n = arr.size();
        vector<int> ans(n);
        for(int i=n-1; i>=0; i--){
            int item = arr[i];

            while(s.top() != -1 && arr[s.top()] >= item){
                s.pop();
            } 
            
            if(s.top() == -1)
                ans[i] = n;
            else
                ans[i] = s.top();
            
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmaller(vector<int> arr){
        stack<int> s;
        s.push(-1);

        int n = arr.size();
        vector<int> ans(n);

        for(int i=0; i<n; i++){
            int item = arr[i];

            while(s.top() != -1 && arr[s.top()] >= item){
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    int largestArea(vector<int> arr){
        vector<int> prev = prevSmaller(arr);
        vector<int> next = nextSmaller(arr);

        int maxArea = INT_MIN;

        for(int i=0; i<arr.size(); i++){
            int length = arr[i];
            int breath = next[i] - prev[i] -1;
            int newArea = (length > breath)? breath*breath : length*length;
            maxArea = max(maxArea, newArea);
        }
        return maxArea;
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = INT_MIN;

        vector<int> histogram(matrix[0].size(), 0);

        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<histogram.size(); j++){
                if(matrix[i][j] == '1'){
                    histogram[j]++;
                }
                else{
                    histogram[j] = 0;
                }
            }
            maxi = max(maxi, largestArea(histogram));
        }
        return maxi;

    }
};