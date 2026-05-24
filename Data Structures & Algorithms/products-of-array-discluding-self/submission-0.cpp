class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left; 
        vector<int> right;
        int leftPi = 1;
        int rightPi = 1;
        int count = 0;
        int len = nums.size() - 1; 
        for (int i = 0; i < nums.size(); i++){
            
            leftPi = leftPi*nums[i];
            rightPi = rightPi*nums[len-i]; 

            left.push_back(leftPi);
            right.push_back(rightPi);
        }

        vector<int> res; 
        for (int i = 0; i < nums.size(); i++){
            if (i == 0) {res.push_back(right[len-1]);}
            else if (i == len) {res.push_back(left[i-1]);}
            else {
                res.push_back(left[i-1] * right[len-1-i]);
            }
        }

        return res;
    }
};
