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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return build(nums, 0, nums.size() - 1);
    }
private:
    TreeNode* build(vector<int>& nums, int left, int right) {

        if (left > right)
            return nullptr;

        int mid = left + (right - left) / 2;
        
        TreeNode* cur = new TreeNode(nums[mid]);
        cur->left = build(nums, left, mid - 1);
        cur->right = build(nums, mid + 1, right);
        
        return cur;
    }
};
