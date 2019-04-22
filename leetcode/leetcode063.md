```java
class Solution {
    public int uniquePathsWithObstacles(int[][] grid) {
        if(grid == null || grid[0].length == 0){
            return 0;
        }
        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[0].length; j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    continue;
                }
                if(i == 0 && j == 0){
                    grid[i][j] = 1;
                }else if(i == 0){
                    grid[i][j] = grid[i][j-1];
                }else if(j == 0){
                    grid[i][j] = grid[i-1][j];
                }else{
                    grid[i][j] = grid[i-1][j] + grid[i][j-1];
                }
            }
        }
        return grid[grid.length-1][grid[0].length-1];
    }
}
```