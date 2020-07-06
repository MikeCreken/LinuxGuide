class Solution:
    def HasSubtree(self, pRoot1, pRoot2):
        # write code here
        if not pRoot1 or not pRoot2:
            return False
        return self.isSame(pRoot1,pRoot2) or self.HasSubtree(pRoot1.left,pRoot2) or self.HasSubtree(pRoot1.right,pRoot2)
    def isSame(self,p,q):
        if not q:
            return True
        if not p:
            return False
        return p.val==q.val and self.isSame(p.left,q.left) and self.isSame(p.right,q.right)