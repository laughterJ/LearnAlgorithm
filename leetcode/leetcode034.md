```java

class Solution {
    int mid = 0;
    int i, j;
    public int[] searchRange(int[] nums, int target) {
        return searchTarget(nums, 0, nums.length-1, target);
    }
    
    public int[] searchTarget(int[] nums, int l, int r, int target){
        if(l > r) return new int[] {-1,-1};
        mid = (l+r)/2;
        if(target == nums[mid]){
            return searchArray(nums, mid, target);
        }
        if(target < nums[mid]){
            return searchTarget(nums, l , mid-1, target);
        }else{
            return searchTarget(nums, mid+1, r, target);
        }
    }
    
    public int[] searchArray(int[] nums, int index, int target){
        i = index;
        j = index;
        while(i > 0 && nums[i-1] == target) i--;
        while(j < nums.length - 1 && nums[j+1] == target) j++;
        return new int[]{i, j};
    }
}
```