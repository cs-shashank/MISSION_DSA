#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class PairSumFinder {
public:
    vector<vector<int>> findKSmallestPairs(const vector<int>& nums1, const vector<int>& nums2, int k) {
        vector<vector<int>> result;
        if (nums1.empty() || nums2.empty() || k == 0) return result;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        for (int i = 0; i < min((int)nums1.size(), k); ++i) {
            minHeap.push({nums1[i] + nums2[0], i, 0});
        }
        while (!minHeap.empty() && result.size() < k) {
            auto top = minHeap.top(); minHeap.pop();
            int i = top[1], j = top[2];
            result.push_back({nums1[i], nums2[j]});
            if (j + 1 < nums2.size()) {
                minHeap.push({nums1[i] + nums2[j + 1], i, j + 1});
            }
        }
        return result;
    }
};
int main() {
    PairSumFinder finder;
    int n1, n2, k;
    cout << "Enter number of elements in nums1: ";
    cin >> n1;
    vector<int> nums1(n1);
    cout << "Enter " << n1 << " integers for nums1:\n";
    for (int i = 0; i < n1; ++i) cin >> nums1[i];
    cout << "Enter number of elements in nums2: ";
    cin >> n2;
    vector<int> nums2(n2);
    cout << "Enter " << n2 << " integers for nums2:\n";
    for (int i = 0; i < n2; ++i) cin >> nums2[i];
    cout << "Enter the value of k: ";
    cin >> k;
    vector<vector<int>> result = finder.findKSmallestPairs(nums1, nums2, k);
    cout << "The " << k << " pairs with the smallest sums are:\n";
    for (const auto& pair : result) {
        cout << "(" << pair[0] << ", " << pair[1] << ")\n";
    }
    return 0;
}