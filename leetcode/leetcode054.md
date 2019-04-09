```java
class Solution {
    List<Integer> res = new ArrayList<>();
    public List<Integer> spiralOrder(int[][] matrix) {
        if(matrix == null || matrix.length == 0){
            return res;
        }
        int l = 0, t = 0, r = matrix[0].length-1, b = matrix.length-1;
        int sign = 1;
        while(sign != 0){
            if(sign == 1){
                for(int i=l;i<=r;i++){
                    res.add(matrix[t][i]);
                }
                t++;
            }else if(sign == 2){
                for(int i=t;i<=b;i++){
                    res.add(matrix[i][r]);
                }
                r--;
            }else if(sign == 3){
                for(int i=r;i>=l;i--){
                    res.add(matrix[b][i]);
                }
                b--;
                
            }else if(sign == 4){
                for(int i=b;i>=t;i--){
                    res.add(matrix[i][l]);
                }
                l++;
            }
            
            if(t > b || l > r){
                sign = 0;
            }else{
                sign ++;
                sign = sign > 4 ? 1 : sign;
            }
        }
        return res;
    }
}
```