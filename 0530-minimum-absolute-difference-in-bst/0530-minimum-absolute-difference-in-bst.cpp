/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void dfs(TreeNode* v, vector <int> &arr) {
        if (v == nullptr) return;

        arr.push_back(v->val);

        dfs (v->left, arr);
        dfs (v->right, arr);
    }
    int getMinimumDifference(TreeNode* root) {
        vector <int> arr;
        int ans = 1000000;

        dfs (root, arr);

        sort (arr.begin(), arr.end());

        for (int i = 1; i < arr.size(); i++) {
            ans = min (ans, abs (arr[i] - arr[i - 1]));
        }

        return ans;
    }
};