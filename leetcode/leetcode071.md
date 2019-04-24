```java
class Solution {
    public String simplifyPath(String path) {
        Stack<String> stack = new Stack<>();
        String str;
        for(int i=1;i<path.length();i++) {
        	str = "/";
        	while(i < path.length() && path.charAt(i) != '/') {
        		str += path.charAt(i);
        		i++;
        	}
        	deal(stack, str);
        	while(i < path.length() && path.charAt(i) == '/') i++;
        	i--;
        }
        str = "";
        while(!stack.isEmpty()) {
        	str = stack.pop() + str;
        }
        return str == "" ? "/" : str;
    }
    
    public void deal(Stack<String> stack, String str) {
    	switch (str) {
    		case "/":
			case "/.":
				break;
			case "/..":
				if (!stack.isEmpty()) stack.pop();
				break;
			default:
				stack.add(str);
				break;
		}
    }
}
```