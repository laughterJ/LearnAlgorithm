```java
class Solution {
    List<List<Integer>> res = new ArrayList<>();
    List<Integer> array = new ArrayList<>();
    public List<List<Integer>> subsets(int[] nums) {
        dfs(nums, 0);
        return res;
    }
    
    public void dfs(int[] nums, int cur) {
        if(array != null){
            res.add(new ArrayList<>(array));
            if(array.size() == nums.length){
                return;
            }
        }
        for(int i = cur; i < nums.length; i++){
            array.add(nums[i]);
            dfs(nums, i+1);
            array.remove(array.size()-1);
        }
    }
}
```