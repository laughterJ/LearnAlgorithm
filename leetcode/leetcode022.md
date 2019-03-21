```java
class Solution {
	
	private List<String> res = new ArrayList<String>();
	
	public List<String> generateParenthesis(int n) {
        dfs("", n, 0, 0);
        return res;
    }
	
	public void dfs(String cur, int num, int open, int close) {
		if (cur.length() == num * 2) {
			res.add(cur);
			return;
		}
		
		if (open < num) {
			dfs(cur + "(", num, open+1, close);
		}
		if (open > close) {
			dfs(cur + ")", num, open, close+1);
		}
	}
}
```