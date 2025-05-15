#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char i : tasks) {
            freq[i]++;
        }

        priority_queue<int> maxHeap;
        for (auto& i : freq) {
            maxHeap.push(i.second);
        }

        queue<pair<int, int>> cooldown;
        int time = 0;

        while (!maxHeap.empty() || !cooldown.empty()) {
            time++;

            if (!cooldown.empty() && cooldown.front().second == time) {
                maxHeap.push(cooldown.front().first);
                cooldown.pop();
            }

            if (!maxHeap.empty()) {
                int count = maxHeap.top();
                maxHeap.pop();
                count--;
                if (count > 0) {
                    cooldown.push({count, time + n + 1});
                }
            }
        }

        return time;
    }
};

int main() {
    Solution solution;
    vector<char> tasks;
    int n;

    cout << "Enter tasks (as a single string, e.g., AAABBB): ";
    string input;
    cin >> input;

    for (char c : input) {
        tasks.push_back(c);
    }

    cout << "Enter cooldown interval n: ";
    cin >> n;

    int result = solution.leastInterval(tasks, n);
    cout << "Minimum intervals needed: " << result << endl;

    return 0;
}
