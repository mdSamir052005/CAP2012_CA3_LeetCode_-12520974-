#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string result;

        for (char ch : s) {
            if (!result.empty() && result.back() == ch) {
                result.pop_back();
            } else {
                result.push_back(ch);
            }
        }

        return result;
    }
};

int main() {
    Solution obj;

    string s;

    cout << "Enter a string: ";
    cin >> s;

    cout << "Result: " << obj.removeDuplicates(s) << endl;

    return 0;
}