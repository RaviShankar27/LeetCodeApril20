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

    int maxPathAndGlobalUpdate(TreeNode *root, int& global_max) {
        if (root == nullptr) return 0;
       
        int l = max(0, maxPathAndGlobalUpdate(root->left, global_max));
        int r = max(0, maxPathAndGlobalUpdate(root->right, global_max));
        global_max = max(global_max, l + r + root->val);
        return root->val + max(l, r);
    }
    
    int maxPathSum(TreeNode *root) {
        int max = numeric_limits<int>::min();
        maxPathAndGlobalUpdate(root, max);
        return max;
    }


    /* this is buggy code
    void inOrderTraversalOfBT(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return;
        inOrderTraversalOfBT(root->left, result);
        inOrderTraversalOfBT(root->right, result);
        result.push_back(root->val);
        return;
    }
    
    int inOrderTraversalOfBTWithSum(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return 0;
        int sum = 0;
        int left_sum = inOrderTraversalOfBTWithSum(root->left, result);
        int right_sum = inOrderTraversalOfBTWithSum(root->right, result);
        sum = left_sum + right_sum + root->val;
        result.push_back(sum);
        return sum;
    }
    
    int inOrderTraversalOfBTWithLarger(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return 0;
        int larger = 0;
        int left_large = inOrderTraversalOfBTWithLarger(root->left, result);
        int right_large = inOrderTraversalOfBTWithLarger(root->right, result);
        larger = left_large > right_large ? root->val+left_large : root->val+right_large;
        result.push_back(larger);
        return larger;
    }
    
    int max3(int a, int b, int c) {
        if (a>b) {
            return a>c? a : c;
        }
        else {
            return b>c ? b : c;
        }
    }
 
    int maxSumInRange(vector<int>& nums, vector<int>& numsSum, vector<int>& numsLarger) {
        int max = INT_MIN;
        for (int index = 0; index < nums.size(); ++index) {
            int m3 = max3(nums[index], numsSum[index], numsLarger[index]);
            if (m3 > max) {
                max = m3;
            }
        }
        return max;
    }
    
    void printArray(vector<int>& nums) {
        for (auto elem: nums) {
            cout << elem << " ";
        }
        cout << endl;
    }
    
    int maxPathSum(TreeNode* root) {
        vector<int> inOrderArray, inOrderSumArray, inOrderLargerArray;
      
        inOrderTraversalOfBT(root, inOrderArray);
        printArray(inOrderArray);
        inOrderTraversalOfBTWithSum(root, inOrderSumArray);
        printArray(inOrderSumArray);
        inOrderTraversalOfBTWithLarger(root, inOrderLargerArray);
        printArray(inOrderLargerArray);
        
        return maxSumInRange(inOrderArray, inOrderSumArray, inOrderLargerArray);
    }*/

};