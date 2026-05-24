class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set <int> unord_set;
        for (int num : nums){
            if (unord_set.count(num)){
                return true;
            }
            unord_set.insert(num);
        }
        return false;
    }
};