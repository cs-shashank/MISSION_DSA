#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    void dfs(TreeNode* node, string path, vector<string>& output) {
        if (!node) return;

        if (!path.empty()) {
            path += "->";
        }
        path += to_string(node->val);

        if (!node->left && !node->right) {
            output.push_back(path);
            return;
        }

        if (node->left) dfs(node->left, path, output);
        if (node->right) dfs(node->right, path, output);
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> output;
        dfs(root, "", output);
        return output;
    }
};

int main() {
  

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, nullptr, new TreeNode(5));
    root->right = new TreeNode(3);

    Solution solution;
    vector<string> paths = solution.binaryTreePaths(root);

    cout << "Root-to-leaf paths:\n";
    for (const string& path : paths) {
        cout << path << endl;
    }

    return 0;
}
