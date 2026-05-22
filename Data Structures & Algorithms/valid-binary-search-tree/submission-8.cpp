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
    bool isValidBST(TreeNode* root) {
        // In order traversal of the tree and put all values into a vector.
        TreeNode *cur = root;
        int prev = INT_MIN;
        stack<TreeNode*> s;
        while (cur != nullptr || !s.empty()) {
            if (cur != nullptr) {
                s.push(cur);
                cur = cur->left;
            } else {
                cur = s.top();
                s.pop();
                if (cur->val <= prev)
                    return false;
                prev = cur->val;
                cur = cur->right;
            }
        }
        return true;
    }
};

/*
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        // In order traversal of the tree and put all values into a vector.
        vector<int> vals;
        TreeNode *cur = root;
        stack<TreeNode*> s;
        while (cur != nullptr || !s.empty()) {
            while (cur != nullptr) {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            vals.push_back(cur->val);
            cur = cur->right;
        }

        for (int i = 1; i < vals.size(); ++i)
            if (vals[i] <= vals[i - 1])
                return false;
        return true;
    }
*/