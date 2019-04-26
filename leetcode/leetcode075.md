```java
/**
 * 从排序的角度思考的，将首部的2和尾部的0交换
 * 关键就是考虑 1 怎么处理
 */
class Solution {
    public void sortColors(int[] nums) {
        int temp, k;
        int i=0,j=nums.length-1;
        while(i<j){
            if(nums[i] == 1){
                k = i;
                while(k < j && nums[k] != 0) k++;
                if(nums[k] == 0){
                    temp = nums[i];
                    nums[i] = nums[k];
                    nums[k] = temp;
                }else{
                    while(i < j && nums[i] == 1) i++;
                }
            }
            if(nums[j] == 1){
                k = j;
                while(k > i && nums[k] != 2) k--;
                if(nums[k] == 2){
                    temp = nums[j];
                    nums[j] = nums[k];
                    nums[k] = temp;
                }else{
                    while(i < j && nums[j] == 1) j--;
                }
            }
            while(i < j && nums[i] == 0) i++;
            while(j > i && nums[j] == 2) j--;
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
}

/**
 * 还有一种比较取巧的思路，就是遍历一次，记录下0,1,2的数量
 * 然后依次顺序赋值，比较简单
 */
```