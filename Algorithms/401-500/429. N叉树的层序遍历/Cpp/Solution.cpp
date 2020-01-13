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
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>> result;
        queue<pair<int, Node*>> c;
        c.push(make_pair(1, root));
        
        while (!c.empty()) {
            
            pair<int, Node*> cur = c.front();
            c.pop();
            
            if (cur.second == nullptr)
                continue;
            
            if (cur.first > result.size())
                result.push_back(vector<int>());
            
            result[cur.first - 1].push_back(cur.second->val);
            
            for (int i = 0; i < cur.second->children.size(); ++ i) 
                c.push(make_pair(cur.first + 1, cur.second->children[i]));
        }
        
        return result;
    }
};
