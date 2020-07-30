#author xiaolan
class Solution:
    def FindKthToTail(self, Phead, k):
        # write code here
        if Phead==None or k<=0:
            return None
        #假设两个指针，p2指针先走（k-1）步，然后再一起走，当p2为到达终点时，p1就为倒数第k个 数
        p2=Phead
        p1=Phead
        #p2先走，走k-1步，如果k大于链表长度则返回 空，否则的话继续走
        while k>1:
            if p2.next!=None:
                p2=p2.next
                k-=1
            else:
                return None
        #此时两个指针一起 走，一直到p2为最后一个,p1即为所求
        while p2.next!=None:
            p1=p1.next
            p2=p2.next
        return p1