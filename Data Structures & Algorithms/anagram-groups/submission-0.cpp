class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> out;
        std::unordered_map<string, vector<string>> hash;

        // Creating hash string wrt sorted string
        for(string& s : strs){
            string key = s;
            std::sort(key.begin(), key.end());
            hash[key].push_back(s);
        }

        for(auto & key : hash){
            out.push_back(key.second);
        }

        return out;
    }
};
