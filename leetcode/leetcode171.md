```java
class Solution {
    public int titleToNumber(String s) {
        int res = 0;
        for(int i=0;i<s.length();i++){
            res+=(int)(s.charAt(i)-'A'+1)*Math.pow(26,s.length()-1-i);
        }
        return res;
    }
}
```