```java
/**
 * 深搜（暴力查找）
 * 可以通过，但是效率极低
 */
class Solution {
    int num = 0;
    boolean finish = false;
    String res = "";
    public String getPermutation(int n, int k) {
        int[] sign = new int[n+1];
        dfs(0, n, sign, k);
        return res;
    }
    
    public void dfs(int step, int n, int[] sign, int k){
        if(step == n || finish){
            num++;
            if(num == k){
                finish = true; 
            }
            return;
        }
        for(int i=1;i<=n;i++){
            if(sign[i] == 0){
                res += i;
                sign[i] = 1;
                dfs(step+1, n, sign, k);
                if(!finish) {
                	sign[i] = 0;
                    res = res.substring(0, res.length()-1);
                }
            }
        }
    }
}

/**
 * 数学方法
 */
class Solution {
    public String getPermutation(int n, int k) {
        // 计算1-8的阶乘
        int[] fact = new int[9];
        fact[1] = 1;
        for(int i=2;i<9;i++){
            fact[i] = fact[i-1] * i;
        }
        // 存放备选数字
        List<Integer> nums = new ArrayList<>();
        for(int i=1;i<=n;i++) {
        	nums.add(i);
        }
        String res = "";
        // 从0开始计数
        k = k-1;
        for(int i=n;i>1;i--) {
        	res += nums.get(k/fact[i-1]);
    		nums.remove(k/fact[i-1]);
    		k %= fact[i-1];
        }
        res += nums.get(0);
        return res;
    }
}
```