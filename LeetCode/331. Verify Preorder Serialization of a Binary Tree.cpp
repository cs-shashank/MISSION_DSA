#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        string node;
        int diff = 1; // Start with 1 slot for the root

        while (getline(ss, node, ',')) {
            if (--diff < 0) return false; // No available slots
            if (node != "#") diff += 2;   // Non-null node adds 2 slots
        }

        return diff == 0; // All slots should be used up
    }
};

int main() {
    Solution sol;

    string test1 = "9,3,4,#,#,1,#,#,2,#,6,#,#"; // valid
    string test2 = "1,#";                       // invalid
    string test3 = "9,#,#,1";                   // invalid

    cout << boolalpha;
    cout << "Test 1: " << sol.isValidSerialization(test1) << endl;
    cout << "Test 2: " << sol.isValidSerialization(test2) << endl;
    cout << "Test 3: " << sol.isValidSerialization(test3) << endl;

    return 0;
}
