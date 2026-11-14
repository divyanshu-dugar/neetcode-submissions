class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string>freq;

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char val = board[i][j];

                if(val == '.') continue;

                string rowIndex = string(1, val) + " found at row " + to_string(i);
                string columnIndex = string(1, val) + " found at column " + to_string(j);
                string boxIndex = string(1, val) + " found at box " + to_string((i / 3) * 3 + (j / 3));

                if(freq.count(rowIndex) || freq.count(columnIndex) || freq.count(boxIndex)){
                    return false;
                }

                freq.insert(rowIndex);
                freq.insert(columnIndex);
                freq.insert(boxIndex);
            }
        }

        return true;
    }
};
