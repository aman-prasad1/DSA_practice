class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int s = 0, e = n-1;

        while(s <= e){
            int mid = s + (e-s)/2;

            if(letters[mid] > target) e = mid-1;
            else s = mid+1;
        }
        if(s >= n) return letters[0];
        return letters[s];
    }
};
