```java
/**
 * 第一反应是广搜，结果一通操作下来悲催地超时了
 * 下面是参考了大佬的思路，时间复杂度 O(n)
 * 从数组最后往前，判断当前位置能否到达下一个可以到达终点的位置
 * step 用来记录当前位置到下一个可以到达终点位置的步数
 */

class Solution {
    public boolean canJump(int[] nums) {
        int step = 1;
        for(int i=nums.length-2;i>=0;i--){
            if(nums[i] >= step){
                step = 1;
            }else{
                step ++;
            }
        }
    	return step == 1;
    }
}
```