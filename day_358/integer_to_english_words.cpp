class Solution {
    string solve(int num, vector<string>& ones_map, vector<string>& tens_map){
        // this function will return the three digit number in english words

        vector<string> res;

        int hundreds = num / 100;
        if(hundreds){
            res.push_back(ones_map[hundreds] + " Hundred");
        }
        int last_2 = num % 100;
        if(last_2 >= 20){
            int tens = last_2 / 10, ones = last_2 % 10;
            res.push_back(tens_map[tens]);
            if(ones){
                res.push_back(ones_map[ones]);
            }
        }
        else if(last_2){
            res.push_back(ones_map[last_2]);
        }

        if(res.empty()) return "";

        string ans = res[0];
        for(int i=1; i<res.size(); i++){
            ans += " " + res[i];
        }

        return ans;
    }
public:
    string numberToWords(int num) {
        if(num == 0) return "Zero";

        // it contains the unique numbers in letter
        vector<string> ones_map = {
            "", "One", "Two", "Three", "Four", "Five", 
            "Six", "Seven", "Eight", "Nine", "Ten", 
            "Eleven", "Twelve", "Thirteen", "Fourteen", 
            "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
        };
        vector<string> tens_map = {
            "Zero",
            "Ten",
            "Twenty",
            "Thirty",
            "Forty",
            "Fifty",
            "Sixty",
            "Seventy",
            "Eighty",
            "Ninety"
        };

        string postfix[] = {"", " Thousand", " Million", " Billion"};
        int i = 0;
        vector<string> res;

        while(num){
            // get the last three digits from num and convert it in english words using solve function
            int digits = num % 1000;
            string str = solve(digits, ones_map, tens_map);
            if(!str.empty()){
                res.push_back(str + postfix[i]);
            }

            num = num / 1000;
            i++;
        }

        string ans = res[res.size()-1];
        for(int i=res.size()-2; i>=0; i--){
            ans += " " + res[i];
        }
        
        return ans;
    }
};
