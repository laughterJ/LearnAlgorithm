```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        if(nums.length == 0){
            return new int[2];
        }
        Map<Integer, Integer> map = new HashMap<>();
        int num;
        for(int i=0;i<nums.length;i++){
            num = target - nums[i];
            if(map.containsKey(num)){
                return new int[]{map.get(num), i};
            }else{
                map.put(nums[i], i);
            }
        }
        return new int[2];
    }
}
```