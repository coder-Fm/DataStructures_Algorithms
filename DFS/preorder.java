// Definition for a binary tree node.
 public class TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode() {}
      TreeNode(int val) { 
        this.val = val; 
      }
      TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
      }
 }
 
public List<Integer> preorderTraversal(TreeNode root) {
     LinkedList<Integer> preorderList = new LinkedList<>();
     TreeNode node = root;
     while (node != null) {
         // r -> L(null) -> R
         if (node.left == null) {
             preorderList.add(node.val);
             node = node.right;
         }
         // r -> L -> R
         else {
             TreeNode pred = node.left;

             while ((pred.right != null) && (pred.right != node)) {
                 pred = pred.right;
             }

             // r -> L -> R(null)
             if (pred.right == null) {
                 preorderList.add(node.val);
                 pred.right = node;
                 node = node.left;
             }
             // r -> L -> R
             else {
                 pred.right = null;
                 node = node.right;
             }
         }
     }
     return preorderList;
 }
