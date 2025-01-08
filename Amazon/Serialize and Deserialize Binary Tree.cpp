#include<string>
#include<sstream>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s=" ";
        if(root==NULL) return s;
        queue<TreeNode*> que;
        que.push(root);
        s+=to_string(root->val)+",";
        while(!que.empty()){
            TreeNode *temp=que.front();
            que.pop();
            if(temp->left){ s+=to_string(temp->left->val)+","; que.push(temp->left); }
            else s+="#,";
            if(temp->right){ s+=to_string(temp->right->val)+","; que.push(temp->right); }
            else s+="#,";
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string s2=" ";
        TreeNode *root;
        if(data==" ") return root;
        stringstream s(data);
        getline(s,s2,',');
        root=new TreeNode(stoi(s2));
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            TreeNode *temp=que.front();
            que.pop();
            getline(s,s2,',');
            if(s2!="#"){
                temp->left=new TreeNode(stoi(s2));
                que.push(temp->left);
            }
            getline(s,s2,',');
            if(s2!="#"){
                temp->right=new TreeNode(stoi(s2));
                que.push(temp->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
