```java
/**
 * AC 解法
 */
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        if(nums.length < 3){
            return res;
        }
        // 先排序
        Arrays.sort(nums);
        int sum;
        // 遍历，在右边设双指针，寻找满足条件的解
        for(int i=0;i<nums.length;i++){
            int l = i+1;
            int r = nums.length - 1;
            while(l<r){
                List<Integer> target = new ArrayList<>();
                sum = nums[i] + nums[l] + nums[r];
                // 满足条件，则保存
                if(sum == 0){
                    target.add(nums[i]);
                    target.add(nums[l]);
                    target.add(nums[r]);
                    res.add(target);
                    // 在 i 不变的情况下，对 l 和 r 去重
                    while(l<r && nums[l] == nums[l+1]){l++;}
                    while(l<r && nums[r] == nums[r-1]){r--;}
                    l++;
                    r--;
                }else if(sum < 0){
                    l++;
                }else{
                    r--;
                }
            }
            // 对 i 去重 （因为前面已将找到了包含 i 的所有解）
            while(i<nums.length-1 && nums[i] == nums[i+1]){i++;}
        }
        return res;
    }
}


/**
 * 时间优化
 */
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        if(nums.length < 3){
            return res;
        }
        Arrays.sort(nums);
        int sum, l, r, k = nums.length - 1;
        // 由于是递增序列，因此左边界要 <= 0
        for(int i=0;i<nums.length && nums[i] <= 0;i++){
            // 左边界优化（左边界太小，与右边界两数相加仍小于0，增大左边界）
            while(i < k && nums[i] + nums[k-1] + nums[k] < 0) i++;
            l = i+1;
            // 右边界优化（右边界太大，与左边界两数相加仍大于0，缩小右边界）
            while(k > l && nums[i] + nums[l] + nums[k] > 0) k--;
            r = k;
            while(l<r){
                List<Integer> target = new ArrayList<>();
                sum = nums[i] + nums[l] + nums[r];
                if(sum == 0){
                    res.add(Arrays.asList(nums[i], nums[l], nums[r]));
                    while(l<r && nums[l] == nums[l+1]){l++;}
                    while(l<r && nums[r] == nums[r-1]){r--;}
                    l++;
                    r--;
                }else if(sum < 0){
                    l++;
                }else{
                    r--;
                }
            }
            while(i<nums.length-1 && nums[i] == nums[i+1]){i++;}
        }
        return res;
    }
}
```