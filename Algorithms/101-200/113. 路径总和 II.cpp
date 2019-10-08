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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {

        search(root, 0, sum);
        return result;
    }
private:
    void search(TreeNode* root, int cur, int target) {

        if (root == nullptr)
            return;

        if (root->left == nullptr && root->right == nullptr) {

            path.push_back(root->val);
            if (cur + root->val == target)
                result.push_back(path);
            path.pop_back();
            return;
        }

        path.push_back(root->val);

        if (root->left != nullptr)
            search(root->left, cur + root->val, target);
        if (root->right != nullptr)
            search(root->right, cur + root->val, target);
    
        path.pop_back();
    } 

    vector<vector<int>> result;
    vector<int> path;
};
