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
    void solve(TreeNode* root, vector<string>& st, string s) {
        if(!root) return;
        s += to_string(root->val);
        if(!root->right && !root->left) {
            st.push_back(s);
            return;
        }
        if(root->left) solve(root->left, st, s);
        if(root->right) solve(root->right, st, s);
    }
    int sumNumbers(TreeNode* root) {
        vector<string> st;
        int ans = 0;
        solve(root, st, "");
        for(string s : st) {
            ans += stoi(s);
        }
        return ans;
    }
};