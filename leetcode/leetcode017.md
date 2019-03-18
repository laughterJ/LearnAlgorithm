```java
class Solution {
    private List<String> res = new ArrayList<>();
    private List<String> str = new ArrayList<>();
    
    public List<String> letterCombinations(String digits) {
    	
        if(digits == null || digits.length() < 1){
            return res;
        }
        Map<Character, String> map = new HashMap<>();
        map.put('2', "abc");
        map.put('3', "def");
        map.put('4', "ghi");
        map.put('5', "jkl");
        map.put('6', "mno");
        map.put('7', "pqrs");
        map.put('8', "tuv");
        map.put('9', "wxyz");
        
        for(int i=0;i<digits.length();i++){
            char c = digits.charAt(i);
            str.add(map.get(c));
        }
        if(str.size()>0){
            dfs(0, "");
        }
        
        return res;
    }
    
    public void dfs(int index, String s){
        if(str.size() == index){
            res.add(s);
            return;
        }
        String cur = str.get(index);
        for(int i=0;i<cur.length();i++){
            s += cur.charAt(i);
            dfs(index+1, s);
            s = s.substring(0, s.length()-1);
        }
    }
}
```