#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = static_cast<int>(mat.size());
        int sum = 0;

        for (int i = 0; i < n; ++i) {
            sum += mat[i][i];

            // Add the secondary diagonal only if it's a different cell.
            if (i != n - 1 - i) {
                sum += mat[i][n - 1 - i];
            }
        }

        return sum;
    }
};

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Solution obj;

    cout << "Diagonal Sum = " << obj.diagonalSum(mat) << endl;

    return 0;
}   