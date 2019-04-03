```java
/**
 * 简单的深搜，关键在于去重
 * 
 */
class Solution {
    
    private List<List<Integer>> res = new ArrayList<>();
    private List<Integer> array = new ArrayList<>();
    
    public List<List<Integer>> permuteUnique(int[] nums) {
        Arrays.sort(nums);
        int[] sign = new int[nums.length];
        dfs(nums, sign, 0);
        return res;
    }
    
    public void dfs(int[] nums, int[] sign, int depth) {
        if(depth == nums.length){
            res.add(new ArrayList<>(array));
            return;
        }
        for(int i=0;i<nums.length;i++){
        	// 如果当前元素等于它的前一个，并且前一个没有添加到数组
        	// 也就意味着这个时候如果将当前元素添加到数组，下一个就有可能将前一个元素添加到数组
        	// 因此，需要在这里做处理，从而达到去重的目的
        	if(i>0 && nums[i] == nums[i-1] && sign[i-1]==0) continue;
            if(sign[i] == 0){
                array.add(nums[i]);
                sign[i] = 1;
                dfs(nums, sign, depth+1);
                array.remove(array.size()-1);
                sign[i] = 0;
            }
        }
    }
}
```