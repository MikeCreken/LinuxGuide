public class Solution {
    public boolean HasSubtree(TreeNode root1,TreeNode root2) {
        //先设置标志位result = false，因为一旦匹配成功result就设为true，
        //剩下的代码不会执行，如果匹配不成功，默认返回false
        boolean result = false;
            if(root1 != null && root2 != null){
                if(root1.val == root2.val){
                    result = DoesTree1HaveTree2(root1,root2);
                }
                if(!result){result = HasSubtree(root1.left, root2);}
                if(!result){result = HasSubtree(root1.right, root2);}
            }
            return result;
    }
    public boolean DoesTree1HaveTree2(TreeNode root1,TreeNode root2){
            if(root1 == null && root2 != null) return false;
            if(root2 == null) return true;
            if(root1.val != root2.val) return false;
            return DoesTree1HaveTree2(root1.left, root2.left) && DoesTree1HaveTree2(root1.right, root2.right);
        }
}