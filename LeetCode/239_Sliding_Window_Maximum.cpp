#include <iostream>
#include <vector>
#include <deque>
using namespace std;
class SlidingWindowMax {
public:
    vector<int> findMaxInSlidingWindow(const vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq;

        for (int i = 0; i < nums.size(); ++i) {
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};
int main() {
    SlidingWindowMax swm;
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cout << "Enter window size (k): ";
    cin >> k;
    vector<int> maxValues = swm.findMaxInSlidingWindow(nums, k);
    cout << "Maximum values in each sliding window:\n";
    for (int val : maxValues) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}