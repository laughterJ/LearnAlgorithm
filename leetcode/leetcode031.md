```java
/**
 * 找到倒数第一个非逆序排列的数字，如【1,3,5,4,2】 中的 3
 * 对 3 往后的子序列排序，找到其中第一个大于3的数字，放在3原来的位置
 * 即 【1，4，2，3，5】 
 */
class Solution {
    public void nextPermutation(int[] nums) {
        for(int i=nums.length-1;i>=0;i--){
            if(i > 0 && nums[i] <= nums[i-1]){
                continue;
            }
            if(i==0){
                Arrays.sort(nums);
            }else{
                int temp = nums[i-1];
                Arrays.sort(nums, i-1, nums.length);
                move(nums, i-1, temp);
            }
            return;
        }
    }
    
    public void move(int[] nums, int i, int temp) {
        int ele = temp;
        for(int j=nums.length-1;j>=i;j--) {
            if(nums[j] > temp) {
                ele = nums[j];
                continue;
            }
            nums[j+1] = nums[j];
        }
        nums[i] = ele;
    }
}
```