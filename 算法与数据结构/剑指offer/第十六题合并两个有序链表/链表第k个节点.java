public class Solution {
    public ListNode FindKthToTail(ListNode head,int k) {
        ListNode p2=null,p1=null;
        //两个指针都指向头结点
        p1=head;
        p2=head;
        //记录k值
        int a=k;
        //记录节点的个数
        int count=0;
        //p指针先跑，并且记录节点数，当p指针跑了k-1个节点后，pre指针开始跑，
        //当p指针跑到最后时，pre所指指针就是倒数第k个节点
        while(p1!=null){
            p1=p1.next;
            count++;
            if(k<1){
                p2=p2.next;
            }
            k--;
        }
        //如果节点个数小于所求的倒数第k个节点，则返回空
        if(count<a) return null;
        return p2;
            
    }
}