```java
class Solution {
    public boolean isValid(String s) {
        if(s == null || s.length() == 0){
            return true;
        }
        Stack<Character> stack = new Stack<>();
        stack.push(s.charAt(0));
        char c;
        for(int i=1;i<s.length();i++) {
            c = s.charAt(i);
            if(!stack.isEmpty()){
                switch(stack.peek()){
                    case ')':
                    case ']':
                    case '}':
                        return false;
                    case '(':
                        if(c == ')'){
                            stack.pop();
                        }else{
                            stack.push(c);
                        }
                        break;
                    case '[':
                        if(c == ']'){
                            stack.pop();
                        }else{
                            stack.push(c);
                        }
                        break;
                    case '{':
                        if(c == '}'){
                            stack.pop();
                        }else{
                            stack.push(c);
                        }
                        break;
                }
            }else{
                stack.push(c);
            }
        }
        if(stack.isEmpty()){
            return true;
        }else{
            return false;
        }
    }
}
```