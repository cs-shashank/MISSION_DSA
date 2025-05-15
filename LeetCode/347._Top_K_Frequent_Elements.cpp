#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
class FrequencyAnalyzer {
public:
    vector<int> getTopKFrequent(const vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        for (int num : nums) {
            counter[num]++;
        }
        auto comp = [](pair<int, int>& a, pair<int, int>& b) {
            return a.second < b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> heap(comp);
        for (auto& entry : counter) {
            heap.push({entry.first, entry.second});
        }
        vector<int> result;
        while (k-- > 0 && !heap.empty()) {
            result.push_back(heap.top().first);
            heap.pop();
        }
        return result;
    }
};
int main() {
    FrequencyAnalyzer analyzer;
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cout << "Enter value of k: ";
    cin >> k;
    vector<int> topK = analyzer.getTopKFrequent(nums, k);
    cout << "Top " << k << " frequent elements:\n";
    for (int val : topK) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}