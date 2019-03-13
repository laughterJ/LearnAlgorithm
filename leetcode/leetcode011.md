```java
/**
 * 方法一：前后两个游标，依此往中间靠近，比较maxVal
 */
class Solution {
    public int maxArea(int[] height) {
        int h = height[0] < height[height.length-1] ? height[0] : height[height.length-1];
        int maxVal = h * (height.length - 1);
        for(int i=0,j=height.length-1; j>i;){
            h = height[i] > height[j] ? --j : ++i;
            h = height[i] > height[j] ? height[j] : height[i];
            if((j-i)*h > maxVal){
                maxVal = (j-i)*h;
            }
        }
        return maxVal;
    }
}

/**
 * 方法一优化：不需要每次移动游标都计算
 */
class Solution {
    public int maxArea(int[] height) {
        int i = 0, j = height.length - 1;
        int maxVal, res = 0, curHeight;
        while(i<j){
            if(height[i] < height[j]){
                maxVal = (j-i) * height[i];
                curHeight = height[i];
                // 如果下一个高度小于当前高度，直接跳过
                while(height[++i] <= curHeight && i<j);
            }else{
                maxVal = (j-i) * height[j];
                curHeight = height[j];
                while(height[--j] <= curHeight && i<j);
            }
            if(maxVal > res){
                res = maxVal;
            }
        }
        return res;
    }
}

 ```