#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }

        deque<int> dq;
        int minLen = n + 1;

        for (int i = 0; i <= n; i++) {
            while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
                minLen = min(minLen, i - dq.front());
                dq.pop_front();
            }
            while (!dq.empty() && prefix[i] <= prefix[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        return (minLen == n + 1) ? -1 : minLen;
    }
};

int main() {
    Solution solution;
    vector<int> nums;
    int k, n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        nums.push_back(val);
    }

    cout << "Enter value of k: ";
    cin >> k;

    int result = solution.shortestSubarray(nums, k);
    cout << "Length of shortest subarray with sum at least " << k << ": " << result << endl;

    return 0;
}
