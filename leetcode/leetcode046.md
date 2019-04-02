```java
class Solution {
    List<List<Integer>> res = new ArrayList<>();
    List<Integer> array = new ArrayList<>();
    
    public List<List<Integer>> permute(int[] nums) {
        int[] sign = new int[nums.length];
        dfs(nums, sign, 0);
        return res;
    }
    
    public void dfs(int nums[], int sign[], int depth) {
        if(depth == nums.length){
            res.add(new ArrayList<>(array));
            return;
        }
        for(int i=0;i<nums.length;i++){
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