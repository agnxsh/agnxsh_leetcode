/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> v;
        queue<Node*> q;
        q.push(root);
        if(root==NULL)
        {
            return v;
        }
        while(!q.empty())
        {
            int x= q.size();
            vector<int> v1;
            while(x--)
            {
                Node* front= q.front();
                q.pop();
                for(auto n: front->children)
                {
                    q.push(n);
                }
                v1.push_back(front->val);
            }
            v.push_back(v1);
        }
        return v;
    }
};