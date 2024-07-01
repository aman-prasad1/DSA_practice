class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        vector<string> line;
        int length = 0;
        int i = 0;

        while(i < words.size()){
            if(length + line.size() + words[i].length() > maxWidth){
                int extra_space = maxWidth - length;
                int space = extra_space / max(1, (int)line.size()-1);
                int remainder = extra_space % max(1, (int)line.size()-1);

                for(int j=0; j<max(1, (int)line.size()-1); j++){
                    for(int k=0; k<space; k++) line[j] += " ";
                    if(remainder){
                        line[j] += " ";
                        remainder -= 1;
                    }
                }
                string temp = "";
                for(auto str : line){
                    temp += str;
                }
                ans.push_back(temp);
                line.clear();
                length = 0;
            }
            line.push_back(words[i]);
            length += words[i].size();
            i += 1;
        }

        string last_line = "";
        for(auto str : line) last_line += str + " ";

        if(last_line.size() > 0) last_line.pop_back();
        
        int trail_space = maxWidth - last_line.size();
        string temp = "";
        for(int i=0; i<trail_space; i++){
            temp += " ";
        }
        ans.push_back(last_line + temp);
        return ans;
    }
};
