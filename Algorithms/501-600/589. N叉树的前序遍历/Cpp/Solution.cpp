/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        
        vector<int> result;
        stack<pair<bool, Node*>> c;
        c.push(make_pair(false, root));
        
        while (!c.empty()) {
            
            pair<bool, Node*> cur = c.top();
            c.pop();
            
            if (cur.second == nullptr)
                continue;
            
            if (!cur.first) {
                
                for (int i = cur.second->children.size() - 1; i >= 0; -- i)
                    c.push(make_pair(false, cur.second->children[i]));
                c.push(make_pair(true, cur.second));
            } else {
                
                result.push_back(cur.second->val);
            }
        }
        
        return result;
    }
};
