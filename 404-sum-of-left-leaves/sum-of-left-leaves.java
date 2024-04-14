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
    public int sumOfLeftLeaves(TreeNode root) {
        // level order traversal 
        if (root  == null )return 0 ; 
        int ans=0 ;

        Queue<TreeNode> q = new LinkedList<>() ; 
        q.offer(root ); 


        while (!q.isEmpty()){
            TreeNode frontNode = q.peek()  ; 
            q.poll(); 

            if (frontNode.left!= null && (frontNode.left.left == null && frontNode.left.right == null )) {          
                ans += (frontNode.left.val);
            }


            if (frontNode.left != null ){
                q.offer(frontNode.left);
            }

            if (frontNode.right != null){
                q.offer(frontNode.right);
            }
        }

        return ans;
    }
}