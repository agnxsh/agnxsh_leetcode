/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<Integer> largestValues(TreeNode root) {
        List<Integer> largest = new ArrayList();
        f1(root, largest, 0);
        return largest;
    }
    
    public void f1(TreeNode root, List<Integer> largest, int level)
    {
        if(root==null)
        {
            return;
        }
        if(level==largest.size())
        {
            largest.add(root.val);
        }
        else
        {
            largest.set(level,Math.max(largest.get(level),root.val));
        }
        
        f1(root.left,largest,level+1);
        f1(root.right,largest,level+1);
    }
}