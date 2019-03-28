```java
/**
 * 参考了一位大佬的代码，做了详细的注释
 */
class Solution {
    public boolean isValidSudoku(char[][] board) {
        // 记录第i（0-8）行是否存在数字j
        boolean row[][] = new boolean[9][10];
        // 记录第i（0-8）行是否存在数字j
        boolean column[][] = new boolean[9][10];
        // 记录第i（0-8）个3*3小方块是否存在数字j
        boolean block[][] = new boolean[9][10];
        int num = 0;
        for(int i = 0; i < 9; i ++){
            for(int j = 0; j < 9; j ++){
                if(board[i][j] != '.'){
                    // 字符相减得到当前数字
                    num = board[i][j] - '0';
                    // 将9*9宫格分为9个3*3宫格，规定为0-8
                    // i/3*3 表示 行为0-2（值为0） 行为3-5（值为3） 行为6-8（值为6）
                    // j/3 表示 列为0-2（值为0） 列为3-5（值为1） 行为6-8（值为2）
                    // 相加刚好对应0-8（数字的规律）
                    if(row[i][num] || column[j][num] || block[i/3*3 + j/3][num]){
                        // 一旦这个判断为 true ，则表示在行或列或3*3宫格内存在重复数字
                        return false;
                    }else{
                        // 为flase 则将出现的数字标记为true，表示已存在
                        row[i][num] = true;
                        column[j][num] = true;
                        block[i/3*3 + j/3][num] = true;
                    }
                }
            }
        }
        return true;
    }
}
```