class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int,int> hash;
        std::vector<vector<int>> freq_vec(nums.size()+1);
        std::vector<int> ans;

        // freq counter    
        for (int n : nums){
            hash[n] = 1 + hash[n];
        }

        //freq vector
        for (const auto& entry : hash){
            freq_vec[entry.second].push_back(entry.first);
        }

        for (int i = freq_vec.size() - 1; i > 0; --i){
            for (auto n : freq_vec[i]){
                ans.push_back(n);
                if (ans.size() == k){
                    return ans;
                }
            }
        }

        return ans;
    }
};
