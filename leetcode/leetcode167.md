```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int i = 0;
        int j = nums.length-1;
        int num = target - nums[0];
        while(nums[j] > num){
            j--;
        }
        while(i<j){
            int result = nums[i] + nums[j];
            if(result == target){
                return new int[]{i+1, j+1};
            }else if(result < target){
                i++;
            }else{
                j--;
            }
        }
        return new int[]{};
    }
}
```