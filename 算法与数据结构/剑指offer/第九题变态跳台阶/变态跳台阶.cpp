// author:xiaolan
class Solution{
public:
    int jumpFloorII(int number) {
        if(number<0)
        {
            return -1;
        }
        //通过移位计算2的次方
        return 1<<(number-1);        
    }
};