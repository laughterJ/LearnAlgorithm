```java
class Solution {
    int mid = 0;
    public int search(int[] nums, int target) {
        return search(nums, 0, nums.length-1, target);
    }
    
    public int search(int[] nums, int l, int r, int target) {
        if(l > r) return -1;
        mid = (l+r)/2;
        if(nums[mid] == target) return mid;
        if(nums[mid] < nums[r]){
            if(nums[mid] < target && target <= nums[r]){
                return search(nums, mid + 1, r, target);
            }else{
                return search(nums, l, mid - 1, target);
            }
        }else{
            if(nums[l] <= target && target < nums[mid]){
                return search(nums, l, mid - 1, target);
            }else{
                return search(nums, mid + 1, r, target);
            }
        }
    }
}
```