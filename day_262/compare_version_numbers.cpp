class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.length();
        int m = version2.length();

        int  i = 0, j = 0;
        string rev1 = "";
        string rev2 = "";
        while(i < n && j < m){
            rev1 = "";
            rev2 = "";

            while(i < n && version1[i] != '.'){
                rev1 += version1[i++];
            }
            while(j < m && version2[j] != '.'){
                rev2 += version2[j++];
            }
            i++, j++;

            if(stoi(rev1) < stoi(rev2)) return -1;
            if(stoi(rev1) > stoi(rev2)) return 1;
        }

        while(i < n){
            if(version1[i] != '.' && version1[i] != '0'){
                return 1;
            }
            i++;
        }
        while(j < m){
            if(version2[j] != '.' && version2[j] != '0'){
                return -1;
            }
            j++;
        }
        return 0;
    }
};
