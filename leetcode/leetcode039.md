```java
class Solution {
	List<List<Integer>> res = new ArrayList<>();
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<Integer> array = new ArrayList<>();
        Arrays.sort(candidates);
        search(array, candidates, target, 0);
        return res;
    }
    
    public void search(List<Integer> array,int[] candidates, int target, int index) {
        if(target == 0){
            res.add(new ArrayList<>(array));
            return;
        }
        
        if(target < candidates[0]) return;
        
        for(int i = index; i < candidates.length; i++){
        	array.add(candidates[i]);
            search(array, candidates, target - candidates[i], i);
            array.remove(array.size()-1);
        }
    }
}
```