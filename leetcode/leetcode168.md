```java
class Solution {
    public String convertToTitle(int n) {
        Stack<Character> stack = new Stack<>();
        while(n > 0){
            n--;
            char c = (char)(65+ n%26);
            stack.push(c);
            n = n/26;
        }
        StringBuilder str = new StringBuilder();
        while(!stack.isEmpty()){
            str.append(stack.pop());
        }
        return str.toString();
    }
}
```