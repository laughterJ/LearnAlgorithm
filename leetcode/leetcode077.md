```java
/**
 * 直接深搜
 */
class Solution {
    
    List<List<Integer>> res = new ArrayList<>();
    List<Integer> array = new ArrayList<>();
    
    public List<List<Integer>> combine(int n, int k) {
        dfs(n, k, 0, 1);
        return res;
    }
    
    public void dfs(int n, int k, int step, int cur) {
        if(k == step){
            res.add(new ArrayList<>(array));
            return;
        }
        for(int i=cur;i<=n;i++){
            array.add(i);
            dfs(n, k, step+1, i+1);
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
    
    public List<List<Integer>> combine(int n, int k) {
        dfs(n, k, 0, 1);
        return res;
    }
    
    public void dfs(int n, int k, int step, int cur) {
        if(k == step){
            res.add(new ArrayList<>(array));
            return;
        }
        // 当 cur 后面的数字少于还需要的数字数量时，不需要再遍历
        for(int i = cur; i <= n-(k-array.size())+1;i++){
            array.add(i);
            dfs(n, k, step+1, i+1);
            array.remove(array.size()-1);
        }
    }
}
```