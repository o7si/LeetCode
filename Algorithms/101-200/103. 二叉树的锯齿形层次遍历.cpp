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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> result;

        deque<pair<TreeNode*, int>> c;
        c.push_front(make_pair(root, 1));

        int curLevel = 1;
        while (!c.empty()) {

            if (curLevel & 1) {

                // 由左向右
                while (!c.empty() && c.front().second == curLevel) {

                    pair<TreeNode*, int> cur = c.front();
                    c.pop_front();

                    if (cur.first == nullptr)
                        continue;

                    if (cur.second > result.size())
                        result.push_back(vector<int>());
                    result[cur.second - 1].push_back(cur.first->val);

                    c.push_back(make_pair(cur.first->left, cur.second + 1));
                    c.push_back(make_pair(cur.first->right, cur.second + 1));
                } 
            } else {

                // 由右向左
                while (!c.empty() && c.back().second == curLevel) {

                    pair<TreeNode*, int> cur = c.back();
                    c.pop_back();

                    if (cur.first == nullptr)
                        continue;

                    if (cur.second > result.size())
                        result.push_back(vector<int>());
                    result[cur.second - 1].push_back(cur.first->val);

                    c.push_front(make_pair(cur.first->right, cur.second + 1));
                    c.push_front(make_pair(cur.first->left, cur.second + 1));
                }
            }

            ++ curLevel;
        }

        return result;
    }
};
