#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int circular = 0;
        int square = 0;

        for (int student : students) {
            if (student == 0)
                circular++;
            else
                square++;
        }

        for (int sandwich : sandwiches) {
            if (sandwich == 0) {
                if (circular == 0)
                    return square;
                circular--;
            } else {
                if (square == 0)
                    return circular;
                square--;
            }
        }

        return 0;
    }
};

int main() {
    vector<int> students = {1, 1, 0, 0};
    vector<int> sandwiches = {0, 1, 0, 1};

    Solution obj;

    cout << "Students unable to eat: "
         << obj.countStudents(students, sandwiches)
         << endl;

    return 0;
}