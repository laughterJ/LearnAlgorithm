```java
/**
 * 常规思路，效率很低
 */
class Solution {
    public String countAndSay(int n) {
        if(n==1) return "1";
        String str = "1", res = "";
        int num = 1;
        for(int i=1;i<n;i++){
            res = "";
            for(int j=0;j<str.length();j++){
                if(j+1 < str.length() && str.charAt(j) == str.charAt(j+1)){
                    num++;
                    continue;
                }
                res = res + num + str.charAt(j);
                num = 1;
            }
            str = res;
        }
        return res;
    }
}


/**
 * 时间优化
 */
class Solution {
    public String countAndSay(int n) {
        if(n==1) return "1";
        if(n==2) return "11";
        String str = "11";
        for(int i=3;i<=n;i++){
            str = getNext(str);
        }
        return str;
    }
    
    public String getNext(String str) {
        char c = str.charAt(0);
        int count = 1;
        StringBuilder sb = new StringBuilder();
        for(int i=1;i<str.length();i++){
            if(str.charAt(i) == c){
                count++;
            }else{
                sb.append(count);
                sb.append(c);
                c = str.charAt(i);
                count = 1;
            }
        }
        sb.append(count);
        sb.append(c);
        return sb.toString();
    } 
}
```