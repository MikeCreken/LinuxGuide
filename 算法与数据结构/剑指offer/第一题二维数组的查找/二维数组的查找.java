public class Solution {
    public boolean Find(int target, int [][] array) {
       //获取行数 列数
        int row=0;
        int col=array[0].length-1;
        //从右边开始遍历
        while(row<=array.length-1&&col>=0){
            if(target==array[row][col])
                return true;
            else if(target>array[row][col])
                row++;
            else
                col--;
        }
        return false;

    }
    
}
