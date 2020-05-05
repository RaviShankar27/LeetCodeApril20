/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty()) return nullptr;
        TreeNode * root = new TreeNode(preorder[0]);
        TreeNode* parent = nullptr;

        stack<TreeNode*> parents;
        parents.push(root);

        for (int index = 1; index < preorder.size(); ++index) {
            parent = nullptr;
            while(!parents.empty() && preorder[index] > parents.top()->val) {
                parent = parents.top();
                parents.pop();
            }
            
            if (parent) {    
                TreeNode* right = new TreeNode(preorder[index]);
                parent->right = right;
                parents.push(right);
            }
            else {
                TreeNode* left = new TreeNode(preorder[index]);
                parents.top()->left = left;
                parents.push(left);
            }
        }
        
        return root;
    }
};