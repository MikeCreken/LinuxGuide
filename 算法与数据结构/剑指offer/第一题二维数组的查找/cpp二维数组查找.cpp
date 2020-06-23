class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        //获取行数和列数
        int rows = array.size();
        int cols = array[0].size();
        if(!array.empty()&&cols>0){
            //从二维数组的右边开始比较
            int row = 0;
            int col = cols -1;
            while(row<rows&&col>=0)
            {
                if(array[row][col]==target){
                    return true;
                }else if(array[row][col]>target)
                {
                    --col;
                }else{
                    ++row;
                }
            }
        }
        return false;
    }
};