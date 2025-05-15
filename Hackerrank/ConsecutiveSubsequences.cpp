#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long cDS(int n, int k, const vector<int>& arr) {
    vector<long long> count(k, 0);
    count[0] = 1;
    long long prefixSum = 0;
    long long result = 0;

    for (int i = 0; i < n; ++i) {
        prefixSum += arr[i];
        int mod = ((prefixSum % k) + k) % k;
        result += count[mod];
        count[mod]++;
    }

    return result;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        cout << cDS(n, k, arr) << endl;
    }

    return 0;
}