class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        int len = 0;
        for(string str : strs){
            len = str.size();
            res +=  to_string(len) + '#' + str;
        }
        return res;
    }

    vector<string> decode(string s) {
       vector<string> res;
        int i = 0;
        while (i < s.size()){
            int j = i;
            while(s[j] != '#'){
                j++;
            }
            int length = stoi(s.substr(i, j-i));
            i = j+1;
            j = i + length;
            res.push_back(s.substr(i, length));
            i = j;
        }
        return res;
    }
};
