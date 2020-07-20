//author xiaolan
//灵活使用短路效应
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        //如果两树任何一个根节点为空则false
        if(pRoot2 == NULL || pRoot1 == NULL )
            return false;
        return isSubtree(pRoot1, pRoot2)|| HasSubtree(pRoot1->left,pRoot2) || HasSubtree(pRoot1->right,pRoot2);
    }
      
    bool isSubtree(TreeNode* pRoot1 , TreeNode* pRoot2){
        if(pRoot2 == NULL)
            return true;
        if(pRoot1 == NULL)
            return false;
        //逐个节点比较
        return pRoot1->val == pRoot2->val && isSubtree(pRoot1->left,pRoot2->left) && isSubtree(pRoot1->right,pRoot2->right);
    }
};