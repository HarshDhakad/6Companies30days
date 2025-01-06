/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int findmax(map<TreeNode*, TreeNode*>& m, TreeNode* target) {
        queue<TreeNode*> q;
        q.push(target);
        map<TreeNode*, int> vis;
        vis[target] = 1;
        int maxi = 0;
        while (!q.empty()) {
            int size = q.size();
            int fl = 0;
            for (int i = 0; i < size; i++) {
                auto node = q.front();
                q.pop();

                if (node->left && !vis[node->left]) {
                    fl = 1;
                    vis[node->left] = 1;
                    q.push(node->left);
                }
                if (node->right && !vis[node->right]) {
                    fl = 1;
                    vis[node->right] = 1;
                    q.push(node->right);
                }
                if (m[node] && !vis[m[node]]) {
                    fl = 1;
                    vis[m[node]] = 1;
                    q.push(m[node]);
                }
            }
            if (fl)
                maxi++;
        }
        return maxi;
    }
    TreeNode* maptoparent(TreeNode* root, map<TreeNode*, TreeNode*>& m,
                          int start) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res;
        while (!q.empty()) {
            TreeNode* node = q.front();
            if (node->val == start)
                res = node;
            q.pop();
            if (node->left) {
                m[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                m[node->right] = node;
                q.push(node->right);
            }
        }

        return res;
    }
    int amountOfTime(TreeNode* root, int start) {
        if (root == NULL)
            return 0;
        map<TreeNode*, TreeNode*> m;
        TreeNode* target = maptoparent(root, m, start);
        int maxi = findmax(m, target);
        return maxi;
    }
};
