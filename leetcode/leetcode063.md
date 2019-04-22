```java
class Solution {
    public int uniquePathsWithObstacles(int[][] grid) {
        if(grid == null || grid[0].length == 0){
            return 0;
        }
        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[0].length; j++){
                // 若当前位置有障碍物，则置0，并且执行下一次循环
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    continue;
                }
                if(i == 0 && j == 0){
                    // 若当前位置为起点，置为1
                    grid[i][j] = 1;
                }else if(i == 0){
                    // 若当前位置为第一行，则到达当前位置的路径数等于前一位置路径数
                    grid[i][j] = grid[i][j-1];
                }else if(j == 0){
                    // 若当前位置为第一列，则到达当前位置的路径数等于前一位置路径数
                    grid[i][j] = grid[i-1][j];
                }else{
                    // 否则，当前位置路径数为上和左两位置路径和
                    grid[i][j] = grid[i-1][j] + grid[i][j-1];
                }
            }
        }
        return grid[grid.length-1][grid[0].length-1];
    }
}
```