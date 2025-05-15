#include <iostream>
#include <cmath>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int moves = 0;

    // DFS helper that returns net coins excess (positive) or need (negative)
    int dfs(TreeNode* root) {
        if (!root) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        moves += abs(left) + abs(right);

        // Return this node's excess to parent
        return root->val + left + right - 1;
    }

public:
    int distributeCoins(TreeNode* root) {
        moves = 0;
        dfs(root);
        return moves;
    }
};

int main() {
  
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(0);
    root->right = new TreeNode(0);

    Solution solution;
    int result = solution.distributeCoins(root);
    cout << "Minimum number of moves: " << result << endl;

    return 0;
}
