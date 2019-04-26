```java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if(matrix == null || matrix.length == 0 || matrix[0].length == 0){
            return false;
        }
        int i;
        for(i=0;i<matrix.length;i++){
            if(matrix[i][matrix[i].length-1] >= target){
                if(matrix[i][matrix[i].length-1] == target){
                    return true;
                }
                break;
            }
        }
        if(i == matrix.length){
            return false;
        }else{
            return binarySearch(0, matrix[i].length-1, target, matrix[i]);
        }
    }
    
    public boolean binarySearch(int l, int r, int target, int[] matrix){
        if(l > r){
            return false;
        }
        int mid = (l + r) / 2;
        if(matrix[mid] == target){
            return true;
        }else if(matrix[mid] > target){
            return binarySearch(l, mid-1, target, matrix);
        }else{
            return binarySearch(mid+1, r, target, matrix);
        }
    }
}
```