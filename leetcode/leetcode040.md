```java
class Solution {
    List<List<Integer>> res = new ArrayList<>();
    List<Integer> array = new ArrayList<>();
    
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        search(candidates, target, 0);
        return res;
    }
    
    public void search(int[] candidates, int target, int index) {
        if(target == 0){
            if(!res.contains(array)){
                res.add(new ArrayList(array));
            }
            return;
        }
        if(index >= candidates.length || candidates[index] > target){
            return;
        }
        for(int i=index;i<candidates.length;i++){
            array.add(candidates[i]);
            search(candidates, target-candidates[i], i+1);
            array.remove(array.size()-1);
        }
    }
}

/**
 * 时间优化
 */
class Solution {
    List<List<Integer>> res = new ArrayList<>();
    List<Integer> array = new ArrayList<>();
    
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        search(candidates, target, 0);
        return res;
    }
    
    public void search(int[] candidates, int target, int index) {
        if(target == 0){
            res.add(new ArrayList(array));
            return;
        }
        if(index >= candidates.length || candidates[index] > target){
            return;
        }
        for(int i=index;i<candidates.length;i++){
            if(i != index && candidates[i-1] == candidates[i]) {
                continue;
            }
            array.add(candidates[i]);
            search(candidates, target-candidates[i], i+1);
            array.remove(array.size()-1);
        }
    }
}
```