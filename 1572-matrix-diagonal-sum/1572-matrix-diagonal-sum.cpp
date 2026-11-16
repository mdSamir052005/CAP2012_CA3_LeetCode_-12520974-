class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0, y = mat.size() - 1;

        for (int i = 0; i < mat.size(); i++) {
            sum += mat[i][i]; // Primary diagonal

            // Avoid counting the center element twice
            if (i != y)
                sum += mat[i][y]; // Secondary diagonal

            y--;
        }
        return sum;
    }
};