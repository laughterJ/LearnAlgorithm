```java
/**
 * 数学题
 * 实际就是从 m+n-2 步中选 m-1 步往下走
 * 或者说从 m+n-2 步中选 n-1 步往右走
 * 即 计算 C(m+n-2, m-1)
 */
class Solution {
    public int uniquePaths(int m, int n) {
        int stepSum = m + n - 2;
        int stepSelect = Math.max(m-1,n-1);
        long pathNum = 1;
        for(int i=stepSelect+1;i<=stepSum;i++){
            pathNum *= i;
        }
        for(int i=1;i<=stepSum-stepSelect;i++){
            pathNum /= i;
        }
        return (int)pathNum;
    }
}
```