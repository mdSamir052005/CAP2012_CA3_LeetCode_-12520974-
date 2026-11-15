
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            int curr = (i == n) ? 0 : heights[i];

            while (!st.empty() && heights[st.top()] > curr) {
                int h = heights[st.top()];
                st.pop();

                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * width);
            }

            st.push(i);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> heights(cols, 0);
        int ans = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }

            ans = max(ans, largestRectangleArea(heights));
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    cout << obj.maximalRectangle(matrix);

    return 0;
}
