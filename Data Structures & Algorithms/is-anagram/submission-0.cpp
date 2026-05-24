class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()){
            return false;
        }
        
        std::unordered_map<char, int> hash_s;
        std::unordered_map<char, int> hash_t;
        
        for (int i = 0; i < s.size(); i++){
            hash_s[s[i]]++;
            hash_t[t[i]]++;
        }

        return hash_s == hash_t;
    }
};
