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
    int minCameraCover(TreeNode* root) {
        int sum=0;
        if(dfs(root,sum)==0)
        {
            sum++;
            
        }
        return sum;
    }
    
    int dfs(TreeNode * tr, int &sum)
    {
        if(!tr)return 1;
        int l=dfs(tr->left,sum), r=dfs(tr->right,sum);
        
        if(l==0 || r==0)
        {
            sum+=1;
            return 2;
        }
        
        else if(l==2 || r==2)
        {
            return 1;
        }
        else
        {
            return 0;
        }
        return -1;
    }
};