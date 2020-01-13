/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        
        stack<pair<TreeNode*, bool>> c;
        c.push(make_pair(root, false));
        while (!c.empty()) {

            pair<TreeNode*, bool> cur = c.top();
            c.pop();

            if (cur.first == nullptr)
                continue;

            if (!cur.second) {
                
                c.push(make_pair(cur.first->right, false));
                c.push(make_pair(cur.first, true));
                c.push(make_pair(cur.first->left, false));
            } else {

                inOrder.push_back(cur.first);
            }
        }

        this->index = 0;
    }
    
    /** @return the next smallest number */
    int next() {
        
        return inOrder[index ++]->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        
        return index < inOrder.size();
    }
private:
    vector<TreeNode*> inOrder;
    int index;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
