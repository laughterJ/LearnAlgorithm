```java
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        if(nums.length < 3){
            return 0;
        }
        Arrays.sort(nums);
        int l,r;
        int sum, minVal = nums[0] + nums[1] + nums[2];
        for(int i=0;i<nums.length;i++){
        	while(i > 0 && i < nums.length && nums[i] == nums[i-1]) i++;
            l = i + 1;
            r = nums.length-1;
            while(l < r){
                sum = nums[i] + nums[l] + nums[r];
                if(sum == target){
                    return sum;
                }
                if(sum < target){
                    l++;
                }else{
                    r--;
                }
                if(Math.abs(sum - target) < Math.abs(minVal - target)){
                    minVal = sum;
                }
            }
        }
        return minVal;
    }
}
```