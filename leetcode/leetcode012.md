```java
class Solution {
    public String intToRoman(int num) {
        int cur;
        Stack<String> stack = new Stack<>();
        String[] ch = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        int a = -4, b = -3, c = -2, d = -1;
        while(num != 0){
            cur = num % 10;
            a+=4;
            b+=4;
            c+=4;
            d+=4;
            switch(cur){
                case 1:
                case 2:
                case 3:
                    for(int i=0;i<cur;i++){
                        stack.push(ch[a]);
                    }
                    break;
                case 4:
                    stack.push(ch[b]);
                    break;
                case 5:
                    stack.push(ch[c]);
                    break;
                case 6:
                case 7:
                case 8:
                    for(int i=0;i<cur%5;i++){
                        stack.push(ch[a]);
                    }
                    stack.push(ch[c]);
                    break;
                case 9:
                    stack.push(ch[d]);
                    break;
                default:
                    break;
            }
            num /= 10;
        }
        String res = "";
        while(!stack.isEmpty()){
            res+=stack.peek();
            stack.pop();
        }
        return res;
    }
}

/**
 * 优化
 */
class Solution {
    public String intToRoman(int num) {
        int[] mInteger = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        String[] mRoman = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        String res = "";
        for(int i=0;i<13;i++){
            while(num >= mInteger[i]){
                res+=mRoman[i];
                num-=mInteger[i];
            }
        }
        return res;
    }
}
```