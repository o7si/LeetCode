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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        this->inorder = inorder;
        this->postorder = postorder;

        return build(0, inorder.size() - 1, 0, postorder.size() - 1);
    }
private:
    TreeNode* build(int inL, int inR, int postL, int postR) {

        if (inL > inR)
            return nullptr;

        TreeNode* cur = new TreeNode(postorder[postR]);

        int pos = inL;
        while (pos <= inR && inorder[pos] != postorder[postR])
            ++ pos;

        int cntL = pos - inL;
        int cntR = inR - pos;
        cur->left = build(inL, pos - 1, postL, postL + cntL - 1);
        cur->right = build(pos + 1, inR, postL + cntL - 1 + 1, postR - 1);

        return cur;
    }

    vector<int> inorder;
    vector<int> postorder;
};
