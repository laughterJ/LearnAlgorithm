```java
/**
 * 整体思路就是逐层进行旋转
 * 关键在于旋转的思路
 */
class Solution {
    public void rotate(int[][] matrix) {
        // matrix.length/2 算出有几层
        for(int i=0;i<matrix.length/2;i++){
            rotate(matrix, i);
        }
    }
    
    /**
     * n 用来记录当前是第几层，n=0表示第一层
     */
    public void rotate(int[][] matrix, int n) {
        int len = matrix.length;
        // 我的思路是 左->上  下->左  右->下  上->右
        // 因此上边的数字会被覆盖掉，需要提前存起来
        int[] temp = new int[len];
        for(int i=n;i<len-n;i++){
            temp[i-n] = matrix[n][i];
        }

        for(int i=n;i<len-1-n;i++){
            // 左->上
            matrix[n][len-1-i] = matrix[i][n];
            // 下->左
            matrix[i][n] = matrix[len-1-n][i];
            // 右->下
            matrix[len-1-n][i] = matrix[len-1-i][len-1-n];
            // 上->右
            matrix[len-1-i][len-1-n] = temp[len-1-i-n];
        }
    }
}
```