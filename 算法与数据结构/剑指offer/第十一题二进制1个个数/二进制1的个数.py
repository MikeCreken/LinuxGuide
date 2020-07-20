# -*- coding:utf-8 -*-
class Solution:
    def NumberOf1(self, n):
        # write code here
        count = 0
        # 这里注意下 python  该数前面有多少位咱也不了解，截取32位就可以了
        while n&0xffffffff != 0:
            count += 1
            n = n & (n-1)
        return count