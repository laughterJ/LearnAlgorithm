```java
/**
 * 整体思路和 three sum 相似
 * 这里设置两个左边界，即第一个数和第二个数
 * 然后依然是两个指针遍历
 * 关键在于缩小边界 以及 去除重复
 */

class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> res = new ArrayList<>();
        if(nums.length < 4){
            return res;
        }
        Arrays.sort(nums);
        int l,r,len = nums.length, sum;
        for(int i=0;i<len-3;i++){
        	// 最左一数与最右三数相加仍小于target，左边界右移，缩小左边界
            while(i < len && nums[i] + nums[len-3] + nums[len-2] + nums[len-1] < target) i++;
            for(int j=i+1;j<len-2;j++){
            	// 左一左二与最右两数相加仍小于target，左二边界右移
                while(j < len && nums[i] + nums[j] + nums[len-2] + nums[len-1] < target) j++;
                // 确定左右指针
                l = j+1;
                r = len-1;
                while(l<r){
                	sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if(sum == target){
                        res.add(Arrays.asList(nums[i], nums[j], nums[l], nums[r]));
                        l++;
                        r--;
                        // 去除左右指针重复数字
                        while(l < r && nums[l] == nums[l-1]) l++;
                        while(l < r && nums[r] == nums[r+1]) r--;
                    }else if(sum > target){
                        r--;
                    }else{
                        l++;
                    }
                }
                // 去除左二边界重复
                while(j < len-1 && nums[j] == nums[j+1]) j++; 
            }
            // 去除左一边界重复
            while(i < len-1 && nums[i] == nums[i+1]) i++; 
        }
        return res;
    }
}
```