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
    TreeNode* addOneRow(TreeNode* root, int val, int d) {
        if(d==1)
        {
            TreeNode* newroot = new TreeNode(val);
            newroot->left = root;
            return newroot;
        }
        else if(d==0)
        {
            TreeNode* newroot = new TreeNode(val);
            newroot->right = root;
            return newroot;
        }
        
        if(root==NULL) return NULL;
        
        if(d==2)
        {
            root->left = addOneRow(root->left,val,1);
            root->right = addOneRow(root->right,val,0);
            return root;
        }
        
        else if(d>2)
            
        {
            root->left = addOneRow(root->left,val,d-1);
            root->right = addOneRow(root->right,val,d-1);
            
        }
            return root;
    }
};