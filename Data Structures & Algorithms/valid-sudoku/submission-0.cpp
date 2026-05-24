class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& mat) {
        
        std::unordered_set<char> rows[9];
        std::unordered_set<char> cols[9];
        std::unordered_set<char> box[9];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                //get the val
                char val = mat[i][j];

                if (val == '.') continue;

                if(rows[i].find(val) != rows[i].end()){
                    //duplicate found
                    return false; 
                }
                rows[i].insert(val);

                if(cols[j].find(val) != cols[j].end()){
                    //duplicate found
                    return false;
                }
                cols[j].insert(val);

                // Calculate the index for the next 3x3 block
                int idx = (i/3)*3 + j/3;
                if (box[idx].find(val) != box[idx].end()){
                    return false;
                }
                box[idx].insert(val);
            }
        }

        return true;
    }
};
