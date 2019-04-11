```java
class Solution {
    public int[][] generateMatrix(int n) {
        int matrix[][] = new int[n][n];
        int l = 0, t = 0, r = n - 1, b = n - 1;
        int sign = 1;
        int num = 1;
        while(l <= r && t <= b){
            if(sign == 1){
                for(int i=l;i<=r;i++){
                    matrix[t][i] = num++;
                }
                sign = 2;
                t++;
            }else if(sign == 2){
                for(int i=t;i<=b;i++){
                    matrix[i][r] = num++;
                }
                sign = 3;
                r--;
            }else if(sign ==3){
                for(int i=r;i>=l;i--){
                    matrix[b][i] = num++;
                }
                sign = 4;
                b--;
            }else{
                for(int i=b;i>=t;i--){
                    matrix[i][l] = num++;
                }
                sign = 1;
                l++;
            }
        }
        return matrix;
    }
}
```