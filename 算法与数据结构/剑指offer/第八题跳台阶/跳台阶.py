# -*- coding:utf-8 -*-
class Solution:
    def jumpFloor(self, n):
        # write code here
        res = [1, 1, 2]
        while len(res) <= n:
            res.append(res[-1] + res[-2])
        return res[n]